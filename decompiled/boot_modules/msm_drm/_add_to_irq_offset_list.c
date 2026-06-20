__int64 __fastcall add_to_irq_offset_list(__int64 a1, int a2, unsigned int a3, int a4)
{
  unsigned __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x0
  __int64 *v11; // x1
  unsigned int v12; // w8

  if ( a2 > 2 )
  {
    if ( a2 != 3 )
    {
      if ( a2 == 4 )
      {
        if ( a3 > 4 )
          goto LABEL_27;
      }
      else if ( a3 >= 5 )
      {
        goto LABEL_27;
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  if ( !a2 )
  {
    if ( a3 <= 3 )
      goto LABEL_11;
LABEL_27:
    printk(&unk_24395A, "_add_to_irq_offset_list");
    return (unsigned int)-22;
  }
  if ( a2 == 1 )
  {
LABEL_10:
    if ( a3 <= 9 )
      goto LABEL_11;
    goto LABEL_27;
  }
  if ( a3 > 2 )
    goto LABEL_27;
LABEL_11:
  v8 = *(_QWORD *)(a1 + 21992);
  v9 = a1 + 21992;
  while ( v8 != v9 )
  {
    if ( *(_DWORD *)(v8 + 16) == a2 && *(_DWORD *)(v8 + 20) == a3 )
    {
      if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_DWORD *)(v8 + 24) == a4 )
        {
          if ( (_drm_debug & 4) != 0 )
            printk(&unk_21E4C1, (unsigned int)a2);
          else
            printk(&unk_27469E, "_add_to_irq_offset_list");
          return 0;
        }
        else
        {
          printk(&unk_21A460, "_add_to_irq_offset_list");
          return (unsigned int)-22;
        }
      }
      break;
    }
    v8 = *(_QWORD *)v8;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "adding intr type %d idx %d offset 0x%x\n", a2, a3, a4);
  v10 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  if ( v10 )
  {
    *(_QWORD *)v10 = v10;
    *(_QWORD *)(v10 + 8) = v10;
    v11 = *(__int64 **)(a1 + 22000);
    *(_DWORD *)(v10 + 16) = a2;
    *(_DWORD *)(v10 + 20) = a3;
    *(_DWORD *)(v10 + 24) = a4;
    if ( v10 == v9 || v11 == (__int64 *)v10 || *v11 != v9 )
    {
      _list_add_valid_or_report(v10, v11);
      return 0;
    }
    else
    {
      v12 = 0;
      *(_QWORD *)(a1 + 22000) = v10;
      *(_QWORD *)v10 = v9;
      *(_QWORD *)(v10 + 8) = v11;
      *v11 = v10;
    }
  }
  else
  {
    printk(&unk_23C887, "_add_to_irq_offset_list");
    return (unsigned int)-12;
  }
  return v12;
}
