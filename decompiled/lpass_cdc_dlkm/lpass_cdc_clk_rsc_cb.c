__int64 __fastcall lpass_cdc_clk_rsc_cb(__int64 a1, __int16 a2)
{
  __int64 v2; // x20
  void *v5; // x0

  if ( !a1 )
  {
    v5 = &unk_D7F9;
LABEL_13:
    printk(v5, "lpass_cdc_clk_rsc_cb");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
  {
    v5 = &unk_D0BD;
    goto LABEL_13;
  }
  mutex_lock(v2 + 8);
  switch ( a2 )
  {
    case 4:
      *(_WORD *)(v2 + 208) = 0;
      break;
    case 11:
      *(_BYTE *)(v2 + 209) = 1;
      break;
    case 5:
      *(_BYTE *)(v2 + 208) = 1;
      break;
  }
  mutex_unlock(v2 + 8);
  return 0;
}
