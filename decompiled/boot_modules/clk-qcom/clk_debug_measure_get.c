__int64 __fastcall clk_debug_measure_get(__int64 a1, unsigned __int64 *a2)
{
  __int64 v2; // x19
  unsigned int v5; // w22
  __int64 parent_by_index; // x23
  __int64 result; // x0
  unsigned int v8; // w0
  __int64 parent; // x0
  _UNKNOWN **v10; // x9
  unsigned int v11; // w0
  __int64 v12; // x28
  _QWORD *v13; // x27
  __int64 v14; // x22
  __int64 v15; // x22
  __int64 v16; // x0
  __int64 v17; // x1
  int v18; // w24
  int v19; // w23
  __int64 v20; // x0
  __int64 v21; // x1
  unsigned __int64 v22; // x23
  __int64 v23; // x22
  unsigned int v24; // w22
  unsigned int v25; // w20
  __int64 v26; // x21
  unsigned int v27; // w20
  unsigned int v28; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = measure;
  if ( measure )
  {
    v28 = 0;
    if ( !(unsigned int)clk_hw_get_num_parents(measure) )
      goto LABEL_11;
    v5 = 0;
    while ( 1 )
    {
      if ( (signed int)v5 >= *(_DWORD *)(v2 - 80) || *(_DWORD *)(*(_QWORD *)(v2 - 88) + 4LL * (int)v5) != -559038737 )
      {
        parent_by_index = clk_hw_get_parent_by_index(v2, v5);
        if ( (clk_is_regmap_clk(parent_by_index) & 1) != 0 )
          break;
      }
      if ( ++v5 >= (unsigned int)clk_hw_get_num_parents(v2) )
        goto LABEL_11;
    }
    result = clk_runtime_get_regmap(parent_by_index);
    if ( !(_DWORD)result )
    {
LABEL_11:
      mutex_lock(&clk_debug_lock);
      v8 = clk_find_and_set_parent(measure, a1);
      if ( v8 )
      {
        v27 = v8;
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_29390);
        v11 = v27;
      }
      else
      {
        parent = clk_hw_get_parent(measure);
        if ( parent )
        {
          v10 = &clk_hw_debug_mux_list;
          while ( 1 )
          {
            v10 = (_UNKNOWN **)*v10;
            if ( v10 == &clk_hw_debug_mux_list )
              break;
            if ( v10 - 3 == (_UNKNOWN **)parent )
            {
              if ( parent == 88 || *(_QWORD *)(parent - 88) )
                break;
              regmap_read(*(_QWORD *)(parent - 56), *(unsigned int *)(parent - 4), &v28);
              if ( v28 )
              {
                *a2 = 0xE8D4A51000uLL / v28;
                goto LABEL_26;
              }
              printk(&unk_28BA6);
              goto LABEL_27;
            }
          }
        }
        v11 = enable_debug_clks(measure);
        if ( !v11 )
        {
          v12 = measure;
          v29 = 0;
          v13 = *(_QWORD **)(measure - 48);
          v14 = *v13;
          if ( !(unsigned int)clk_prepare(*v13) && (unsigned int)clk_enable(v14) )
            clk_unprepare(v14);
          v15 = raw_spin_lock_irqsave(&clk_reg_lock);
          regmap_read(*(_QWORD *)(v12 - 56), *((unsigned int *)v13 + 4), &v29);
          v16 = *(_QWORD *)(v12 - 56);
          v17 = *((unsigned int *)v13 + 4);
          v29 |= 1u;
          regmap_write(v16, v17, v29);
          v18 = run_measurement(4096, *(_QWORD *)(v12 - 56), *((unsigned int *)v13 + 2), *((unsigned int *)v13 + 3));
          v19 = run_measurement(0x20000, *(_QWORD *)(v12 - 56), *((unsigned int *)v13 + 2), *((unsigned int *)v13 + 3));
          v20 = *(_QWORD *)(v12 - 56);
          v21 = *((unsigned int *)v13 + 4);
          v29 &= ~1u;
          regmap_write(v20, v21, v29);
          if ( v19 == v18 )
            v22 = 0;
          else
            v22 = (unsigned __int64)((4800000
                                    * (unsigned __int64)(unsigned int)(10 * v19 + 15)
                                    * (unsigned __int128)0xCCCB6668D99551uLL) >> 64) >> 12;
          raw_spin_unlock_irqrestore(&clk_reg_lock, v15);
          v23 = *v13;
          clk_disable(*v13);
          clk_unprepare(v23);
          *a2 = v22;
          *a2 *= (unsigned int)get_mux_divs(measure);
          disable_debug_clks(measure);
LABEL_26:
          clk_hw_get_name(a1);
LABEL_27:
          v11 = 0;
        }
      }
      v24 = v11;
      mutex_unlock(&clk_debug_lock);
      if ( (unsigned int)clk_hw_get_num_parents(v2) )
      {
        v25 = 0;
        while ( 1 )
        {
          if ( (signed int)v25 >= *(_DWORD *)(v2 - 80)
            || *(_DWORD *)(*(_QWORD *)(v2 - 88) + 4LL * (int)v25) != -559038737 )
          {
            v26 = clk_hw_get_parent_by_index(v2, v25);
            if ( (clk_is_regmap_clk(v26) & 1) != 0 )
              break;
          }
          if ( ++v25 >= (unsigned int)clk_hw_get_num_parents(v2) )
            goto LABEL_36;
        }
        clk_runtime_put_regmap(v26);
      }
LABEL_36:
      result = v24;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
