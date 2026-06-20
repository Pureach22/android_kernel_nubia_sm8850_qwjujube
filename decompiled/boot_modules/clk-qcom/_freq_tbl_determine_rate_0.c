__int64 __fastcall freq_tbl_determine_rate_0(__int64 a1, __int64 a2, _QWORD *a3, int a4)
{
  __int64 freq; // x20
  __int64 result; // x0
  unsigned int v8; // w23
  char flags; // w22
  __int64 parent_by_index; // x0
  __int64 v11; // x21
  unsigned __int64 rate; // x1
  unsigned int v13; // w19
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  if ( a4 )
  {
    freq = qcom_find_freq(a2);
    if ( !freq )
      goto LABEL_9;
  }
  else
  {
    freq = qcom_find_freq_floor(a2);
    if ( !freq )
      goto LABEL_9;
  }
  result = qcom_find_src_index(a1, *(_QWORD *)(a1 - 40), *(unsigned __int8 *)(freq + 8));
  if ( (result & 0x80000000) != 0 )
    goto LABEL_10;
  v8 = result;
  flags = clk_hw_get_flags(a1);
  parent_by_index = clk_hw_get_parent_by_index(a1, v8);
  if ( !parent_by_index )
  {
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v11 = parent_by_index;
  if ( (flags & 4) != 0 )
  {
    rate = *(_QWORD *)freq;
    if ( *(_BYTE *)(freq + 9) )
    {
      if ( !rate )
        rate = a3[1];
      rate = (rate >> 1) + (rate >> 1) * *(unsigned __int8 *)(freq + 9);
    }
    if ( *(_WORD *)(freq + 12) )
      rate = rate * *(unsigned __int16 *)(freq + 12) / *(unsigned __int16 *)(freq + 10);
  }
  else
  {
    rate = clk_hw_get_rate(parent_by_index);
  }
  a3[5] = v11;
  a3[4] = clk_hw_round_rate(v11, rate);
  a3[1] = *(_QWORD *)freq;
  if ( *(_QWORD *)(freq + 16) )
  {
    v15 = *(_QWORD *)(freq + 16);
    v19 = v11;
    result = _clk_determine_rate(v11, &v14);
    if ( !(_DWORD)result )
    {
      result = clk_set_rate(*(_QWORD *)(v11 + 8), v15);
      if ( (_DWORD)result )
      {
        v13 = result;
        printk(&unk_293C6);
        result = v13;
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
