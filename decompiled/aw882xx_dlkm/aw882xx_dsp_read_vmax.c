__int64 __fastcall aw882xx_dsp_read_vmax(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 *v5; // x8
  __int64 v6; // x1
  __int64 *v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x1

  if ( *(_DWORD *)(a1 + 52) >= 8u )
  {
    v5 = *(__int64 **)(a1 + 112);
    v6 = v5[14];
    if ( !v6 )
      v6 = *v5;
    printk(&unk_27130, v6, "aw882xx_dsp_read_vmax");
    return 4294967274LL;
  }
  else
  {
    result = aw882xx_dsp_read_dsp_msg(a1, a2, a2, a3);
    if ( (_DWORD)result )
    {
      v7 = *(__int64 **)(a1 + 112);
      v8 = result;
      v9 = v7[14];
      if ( !v9 )
        v9 = *v7;
      printk(&unk_232F1, v9, "aw882xx_dsp_read_vmax");
      return v8;
    }
  }
  return result;
}
