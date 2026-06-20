__int64 __fastcall devm_clk_register_regmap(__int64 a1, __int64 a2)
{
  __int64 regmap; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  void (__fastcall *v8)(_QWORD); // x9
  __int64 result; // x0
  _UNKNOWN **v10; // x0
  void *v11; // x2

  *(_QWORD *)(a2 + 112) = a1;
  if ( a1 )
  {
    regmap = dev_get_regmap(a1, 0);
    v5 = a1;
    if ( regmap || (v5 = *(_QWORD *)(a1 + 96)) != 0 )
      *(_QWORD *)(a2 + 24) = dev_get_regmap(v5, 0);
  }
  v6 = *(_QWORD *)(a2 + 136);
  if ( (v6 & 3) != 0 )
  {
    v7 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8LL);
    if ( v7 )
    {
      v8 = *(void (__fastcall **)(_QWORD))(v7 + 32);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != 1154662183 )
          __break(0x8229u);
        v8(a2);
        v6 = *(_QWORD *)(a2 + 136);
      }
    }
    if ( (v6 & 1) != 0 )
      return 0;
  }
  if ( (unsigned int)devm_clk_hw_register(a1, a2) )
    goto LABEL_13;
  raw_spin_lock(&clk_regmap_lock);
  v10 = (_UNKNOWN **)(a2 + 96);
  v11 = clk_regmap_list;
  if ( clk_regmap_list == (_UNKNOWN *)(a2 + 96)
    || v10 == &clk_regmap_list
    || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)clk_regmap_list) != &clk_regmap_list )
  {
    _list_add_valid_or_report(v10, &clk_regmap_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)clk_regmap_list) = v10;
    *(_QWORD *)(a2 + 96) = v11;
    *(_QWORD *)(a2 + 104) = &clk_regmap_list;
    clk_regmap_list = (_UNKNOWN *)(a2 + 96);
  }
  raw_spin_unlock(&clk_regmap_lock);
  result = clk_hw_debug_register(a1, a2);
  if ( !(_DWORD)result )
  {
LABEL_13:
    if ( (*(_BYTE *)(a2 + 136) & 4) != 0 )
      clk_debug_register_minidump((__int64 *)a2);
    return 0;
  }
  return result;
}
