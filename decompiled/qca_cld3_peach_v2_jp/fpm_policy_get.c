__int64 __fastcall fpm_policy_get(
        char *a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x22
  unsigned int v14; // w20
  char *v15; // x23
  unsigned int v16; // w24
  _QWORD *i; // x21
  const char *v18; // x2

  if ( !a1 )
  {
    v18 = "%s: fpm_ctx is NULL";
LABEL_13:
    qdf_trace_msg(0x45u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "fpm_policy_get");
    return 0;
  }
  if ( !a2 )
  {
    v18 = "%s: policies is NULL";
    goto LABEL_13;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = 0;
  v14 = 0;
  v15 = a1 + 16;
  v16 = a3;
  *(_DWORD *)(StatusReg + 16) += 512;
  do
  {
    for ( i = *(_QWORD **)&v15[8 * v13]; i; i = (_QWORD *)*i )
    {
      if ( v14 + 1 < v16 )
        a1 = (char *)qdf_mem_copy((void *)(a2 + 104LL * v14++), i, 0x68u);
    }
    ++v13;
  }
  while ( v13 != 8 );
  local_bh_enable_3(a1);
  return v14;
}
