__int64 __fastcall aw882xx_dsp_write_vmax(__int64 a1, const void *a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 *v8; // x8
  unsigned int v9; // w20
  __int64 v10; // x1

  v3 = *(unsigned int *)(a1 + 52);
  if ( (unsigned int)v3 >= 8 )
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = v6[14];
    if ( !v7 )
      v7 = *v6;
    printk(&unk_27130, v7, "aw882xx_dsp_write_vmax");
    return 4294967274LL;
  }
  else
  {
    result = aw882xx_dsp_write_dsp_msg(a1, dword_29B0C[v3], a2, a3);
    if ( (_DWORD)result )
    {
      v8 = *(__int64 **)(a1 + 112);
      v9 = result;
      v10 = v8[14];
      if ( !v10 )
        v10 = *v8;
      printk(&unk_26A5A, v10, "aw882xx_dsp_write_vmax");
      return v9;
    }
  }
  return result;
}
