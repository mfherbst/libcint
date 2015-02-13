/*
 * Copyright (C) 2013  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include "cint_bas.h"
#include "cart2sph.h"
#include "g2e.h"
#include "g3c2e.h"
#include "g2c2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "fblas.h"
#include "c2f.h"
/* <k NABLA NABLA i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (NABLA NABLA i j|R12 |k l) */
static void CINTgout2e_cint2e_ipip1_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs, FINT gout_empty) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const FINT k_l = envs->k_l;
const FINT l_l = envs->l_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
const double *rk = envs->rk;
const double *rl = envs->rl;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double s[9];
G2E_D_I(g1, g0, i_l+1, j_l, k_l, l_l);
G2E_D_I(g2, g0, i_l+0, j_l, k_l, l_l);
G2E_D_I(g3, g1, i_l+0, j_l, k_l, l_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
CINTdset0(9, s);
for (i = 0; i < envs->nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[0] = + (1*s[0]);
gout[1] = + (1*s[3]);
gout[2] = + (1*s[6]);
gout[3] = + (1*s[1]);
gout[4] = + (1*s[4]);
gout[5] = + (1*s[7]);
gout[6] = + (1*s[2]);
gout[7] = + (1*s[5]);
gout[8] = + (1*s[8]);
gout += 9;
} else {
gout[0] += + (1*s[0]);
gout[1] += + (1*s[3]);
gout[2] += + (1*s[6]);
gout[3] += + (1*s[1]);
gout[4] += + (1*s[4]);
gout[5] += + (1*s[7]);
gout[6] += + (1*s[2]);
gout[7] += + (1*s[5]);
gout[8] += + (1*s[8]);
gout += 9;
}}}
void cint2e_ipip1_sph_optimizer(CINTOpt **opt, const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {2, 0, 0, 0, 0, 0, 0, 0};
CINTuse_all_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
FINT cint2e_ipip1_sph(double *opijkl, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env, CINTOpt *opt) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 1, 9};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_cint2e_ipip1_sph;
envs.common_factor *= 1;
return CINT2e_spheric_drv(opijkl, &envs, opt);
}
OPTIMIZER2F_(cint2e_ipip1_sph_optimizer);
C2Fo_(cint2e_ipip1_sph)
/* <k NABLA i|R12 |NABLA j l> : i,j \in electron 1; k,l \in electron 2
 * = (NABLA i NABLA j|R12 |k l) */
static void CINTgout2e_cint2e_ipvip1_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs, FINT gout_empty) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const FINT k_l = envs->k_l;
const FINT l_l = envs->l_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
const double *rk = envs->rk;
const double *rl = envs->rl;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double s[9];
G2E_D_J(g1, g0, i_l+1, j_l+0, k_l, l_l);
G2E_D_I(g2, g0, i_l+0, j_l, k_l, l_l);
G2E_D_I(g3, g1, i_l+0, j_l, k_l, l_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
CINTdset0(9, s);
for (i = 0; i < envs->nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[0] = + (1*s[0]);
gout[1] = + (1*s[1]);
gout[2] = + (1*s[2]);
gout[3] = + (1*s[3]);
gout[4] = + (1*s[4]);
gout[5] = + (1*s[5]);
gout[6] = + (1*s[6]);
gout[7] = + (1*s[7]);
gout[8] = + (1*s[8]);
gout += 9;
} else {
gout[0] += + (1*s[0]);
gout[1] += + (1*s[1]);
gout[2] += + (1*s[2]);
gout[3] += + (1*s[3]);
gout[4] += + (1*s[4]);
gout[5] += + (1*s[5]);
gout[6] += + (1*s[6]);
gout[7] += + (1*s[7]);
gout[8] += + (1*s[8]);
gout += 9;
}}}
void cint2e_ipvip1_sph_optimizer(CINTOpt **opt, const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 1, 0, 0, 0, 0, 0, 0};
CINTuse_all_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
FINT cint2e_ipvip1_sph(double *opijkl, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env, CINTOpt *opt) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 1, 9};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_cint2e_ipvip1_sph;
envs.common_factor *= 1;
return CINT2e_spheric_drv(opijkl, &envs, opt);
}
OPTIMIZER2F_(cint2e_ipvip1_sph_optimizer);
C2Fo_(cint2e_ipvip1_sph)
/* <NABLA k NABLA i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (NABLA i j|R12 |NABLA k l) */
static void CINTgout2e_cint2e_ip1ip2_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs, FINT gout_empty) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const FINT k_l = envs->k_l;
const FINT l_l = envs->l_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
const double *rk = envs->rk;
const double *rl = envs->rl;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double s[9];
G2E_D_K(g1, g0, i_l+1, j_l+0, k_l+0, l_l);
G2E_D_I(g2, g0, i_l+0, j_l, k_l, l_l);
G2E_D_I(g3, g1, i_l+0, j_l, k_l, l_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
CINTdset0(9, s);
for (i = 0; i < envs->nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[0] = + (1*s[0]);
gout[1] = + (1*s[3]);
gout[2] = + (1*s[6]);
gout[3] = + (1*s[1]);
gout[4] = + (1*s[4]);
gout[5] = + (1*s[7]);
gout[6] = + (1*s[2]);
gout[7] = + (1*s[5]);
gout[8] = + (1*s[8]);
gout += 9;
} else {
gout[0] += + (1*s[0]);
gout[1] += + (1*s[3]);
gout[2] += + (1*s[6]);
gout[3] += + (1*s[1]);
gout[4] += + (1*s[4]);
gout[5] += + (1*s[7]);
gout[6] += + (1*s[2]);
gout[7] += + (1*s[5]);
gout[8] += + (1*s[8]);
gout += 9;
}}}
void cint2e_ip1ip2_sph_optimizer(CINTOpt **opt, const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 1, 0, 0, 0, 0, 0};
CINTuse_all_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
FINT cint2e_ip1ip2_sph(double *opijkl, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env, CINTOpt *opt) {
FINT ng[] = {1, 0, 1, 0, 2, 1, 1, 9};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_cint2e_ip1ip2_sph;
envs.common_factor *= 1;
return CINT2e_spheric_drv(opijkl, &envs, opt);
}
OPTIMIZER2F_(cint2e_ip1ip2_sph_optimizer);
C2Fo_(cint2e_ip1ip2_sph)