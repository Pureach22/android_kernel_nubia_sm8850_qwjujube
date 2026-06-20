__int64 __fastcall sub_164A70(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int *v12; // x19
  __int64 v13; // x25
  unsigned __int64 StatusReg; // x5

  StatusReg = _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  atomic_load(v12);
  *(double *)(v13 + 392) = a12;
  *(double *)(v13 + 400) = a6;
  return priv_start_cap_chaninfo(a1, a2, a3, a4, a5, StatusReg);
}
