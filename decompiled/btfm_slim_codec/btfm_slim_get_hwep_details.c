__int64 __fastcall btfm_slim_get_hwep_details(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x22
  __int64 v5; // x21
  unsigned int *property; // x0
  __int64 v7; // x2
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 result; // x0
  void *v11; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 744);
  v4 = *(_QWORD *)(a2 + 1096);
  v5 = *(_QWORD *)(a2 + 1104);
  v12 = 0;
  property = (unsigned int *)of_get_property(v3, "qcom,btslim-address", &v12);
  if ( property )
  {
    *(_DWORD *)(a2 + 1128) = bswap32(*property);
    if ( !v4 )
    {
LABEL_10:
      v11 = &unk_82F0;
LABEL_13:
      result = printk(v11, "btfm_slim_get_hwep_details", v7);
      goto LABEL_8;
    }
  }
  else
  {
    printk(&unk_8F83, "btfm_slim_get_hwep_details", v7);
    *(_DWORD *)(a2 + 1128) = 0;
    if ( !v4 )
      goto LABEL_10;
  }
  if ( !v5 )
    goto LABEL_10;
  v8 = of_get_property(v3, "qcom,btslimrx-channels", &v12);
  if ( v8 )
  {
    *(_BYTE *)(v4 + 18) = *(_BYTE *)(v8 + 3);
    *(_BYTE *)(v4 + 90) = *(_BYTE *)(v8 + 7);
  }
  else
  {
    printk(&unk_89EB, "btfm_slim_get_hwep_details", v9);
  }
  result = of_get_property(v3, "qcom,btslimtx-channels", &v12);
  if ( !result )
  {
    v11 = &unk_8BE1;
    goto LABEL_13;
  }
  *(_BYTE *)(v5 + 18) = *(_BYTE *)(result + 3);
  *(_BYTE *)(v5 + 90) = *(_BYTE *)(result + 7);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
