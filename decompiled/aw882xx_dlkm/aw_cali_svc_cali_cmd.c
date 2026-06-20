__int64 __fastcall aw_cali_svc_cali_cmd(__int64 a1, int a2, char a3, unsigned int a4)
{
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v11; // x20
  __int64 *v12; // x8
  __int64 v13; // x1

  if ( a2 <= 1 )
  {
    if ( !a2 )
      return aw_cali_svc_cali_re(a1, a3 & 1, a4);
    if ( a2 != 1 )
      goto LABEL_17;
    v9 = a3 & 1;
    return aw_cali_svc_cali_f0(a1, v9, a4);
  }
  switch ( a2 )
  {
    case 2:
      v11 = a1;
      result = aw_cali_svc_cali_re(a1, a3 & 1, a4);
      if ( (_DWORD)result )
        return result;
      v9 = a3 & 1;
      a1 = v11;
      return aw_cali_svc_cali_f0(a1, v9, a4);
    case 3:
      v8 = a3 & 1;
      return aw_cali_svc_cali_f0_q(a1, v8, a4);
    case 4:
      v6 = a1;
      result = aw_cali_svc_cali_re(a1, a3 & 1, a4);
      if ( (_DWORD)result )
        return result;
      v8 = a3 & 1;
      a1 = v6;
      return aw_cali_svc_cali_f0_q(a1, v8, a4);
  }
LABEL_17:
  v12 = *(__int64 **)(a1 + 112);
  v13 = v12[14];
  if ( !v13 )
    v13 = *v12;
  printk(&unk_22D5C, v13, "aw_cali_svc_cali_cmd");
  return 4294967274LL;
}
