__int64 __fastcall target_if_is_aspectral_prohibited_by_adfs(
        __int64 result,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _BYTE *v11; // x19
  const char *v12; // x2
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  if ( a3 )
  {
    if ( (*a3 & 1) == 0 )
    {
      if ( !result )
      {
        v11 = a3;
        v12 = "%s: psoc is null.";
        goto LABEL_12;
      }
      v11 = a3;
      if ( !a2 )
      {
        v12 = "%s: Current pdev is null.";
        goto LABEL_12;
      }
      result = ucfg_dfs_get_agile_precac_enable(a2, v13);
      if ( (_DWORD)result )
      {
        v12 = "%s: Get agile precac failed, prohibiting aSpectral";
LABEL_12:
        result = qdf_trace_msg(
                   0x56u,
                   2u,
                   v12,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "target_if_is_aspectral_prohibited_by_adfs");
        *v11 = 1;
        goto LABEL_13;
      }
      if ( v13[0] == 1 )
      {
        v12 = "%s: aDFS preCAC is in progress on one of the pdevs";
        goto LABEL_12;
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x56u,
               2u,
               "%s: Arg(Indication flag for agile spectral prohibition) is null.",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "target_if_is_aspectral_prohibited_by_adfs");
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
