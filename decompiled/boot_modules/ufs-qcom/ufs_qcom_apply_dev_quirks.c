__int64 __fastcall ufs_qcom_apply_dev_quirks(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x10
  int v4; // w8
  unsigned int attr; // w20
  unsigned int v6; // w0
  unsigned int v7; // w0
  int v8; // w0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = raw_spin_lock_irqsave(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 56LL));
  v3 = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 100) = 3077;
  *(_QWORD *)(a1 + 2904) = 50;
  raw_spin_unlock_irqrestore(*(_QWORD *)(v3 + 56), v2);
  v4 = *(_DWORD *)(a1 + 220);
  if ( (v4 & 0x100) != 0 )
  {
    v10 = 0;
    attr = ufshcd_dme_get_attr(a1, 2415919104LL, &v10, 0);
    if ( !attr )
      attr = ufshcd_dme_set_attr(a1, 2415919104LL, 0, v10 | 0x1000u, 0);
    v4 = *(_DWORD *)(a1 + 220);
  }
  else
  {
    attr = 0;
  }
  if ( *(_WORD *)(a1 + 2548) == 325 )
  {
    v4 |= 0x80u;
    *(_DWORD *)(a1 + 220) = v4;
    if ( (v4 & 0x8000) == 0 )
    {
LABEL_8:
      if ( (v4 & 0x10000) == 0 )
        goto LABEL_17;
      goto LABEL_15;
    }
  }
  else if ( (v4 & 0x8000) == 0 )
  {
    goto LABEL_8;
  }
  v10 = 0;
  v6 = ufshcd_dme_get_attr(a1, 363266048, &v10, 0);
  if ( v6 )
  {
    dev_err(*(_QWORD *)(a1 + 64), "Failed getting PA_HIBERN8TIME: %d\n", v6);
  }
  else
  {
    v7 = ufshcd_dme_set_attr(a1, 363266048, 0, (unsigned int)(v10 + 1), 0);
    if ( v7 )
      dev_err(*(_QWORD *)(a1 + 64), "Failed updating PA_HIBERN8TIME: %d\n", v7);
  }
  if ( (*(_DWORD *)(a1 + 220) & 0x10000) != 0 )
  {
LABEL_15:
    v8 = ufshcd_dme_set_attr(a1, 357695488, 0, 74, 1);
    if ( v8 )
      dev_err(*(_QWORD *)(a1 + 64), "Failed (%d) set PA_TX_HSG1_SYNC_LENGTH(%d)\n", v8, 74);
  }
LABEL_17:
  if ( *(_WORD *)(a1 + 2548) == 300 )
    *(_DWORD *)(a1 + 220) |= 0x40u;
  _ReadStatusReg(SP_EL0);
  return attr;
}
