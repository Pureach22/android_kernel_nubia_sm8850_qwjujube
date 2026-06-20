__int64 __fastcall qcom_smp2p_restore(__int64 a1)
{
  __int64 v1; // x20
  unsigned int string; // w21
  __int64 next_available_child; // x0
  __int64 v5; // x22
  _QWORD *v6; // x23
  __int64 v7; // x0
  _QWORD *v8; // x26
  _QWORD *v9; // x2
  __int64 v10; // x0

  v1 = *(_QWORD *)(a1 + 152);
  string = qcom_smp2p_alloc_outbound_item((_QWORD *)v1);
  if ( (string & 0x80000000) == 0 )
  {
    next_available_child = of_get_next_available_child(*(_QWORD *)(a1 + 744), 0);
    if ( !next_available_child )
    {
LABEL_16:
      irq_set_irq_wake(*(unsigned int *)(v1 + 56), 1);
      __dsb(0xEu);
      v10 = *(_QWORD *)(v1 + 136);
      if ( v10 )
      {
        mbox_send_message(v10, 0);
        mbox_client_txdone(*(_QWORD *)(v1 + 136), 0);
      }
      else
      {
        regmap_write(*(_QWORD *)(v1 + 64), *(unsigned int *)(v1 + 72), 1LL << *(_DWORD *)(v1 + 76));
      }
      return string;
    }
    v5 = next_available_child;
    v6 = (_QWORD *)(v1 + 160);
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v7 = _kmalloc_cache_noprof(mbox_send_message, 3520, 104);
      v8 = (_QWORD *)v7;
      if ( !v7 )
      {
        string = -12;
        goto LABEL_20;
      }
      *(_QWORD *)(v7 + 16) = v1;
      *(_DWORD *)(v7 + 96) = 0;
      string = of_property_read_string(v5, "qcom,entry-name", v7 + 24);
      if ( (string & 0x80000000) != 0 )
        break;
      if ( of_find_property(v5, "interrupt-controller", 0) )
      {
        kfree(v8);
      }
      else
      {
        string = qcom_smp2p_outbound_entry((_QWORD *)v1, v8, v5);
        if ( (string & 0x80000000) != 0 )
          break;
        v9 = (_QWORD *)*v6;
        if ( *(_QWORD **)(*v6 + 8LL) != v6 || v8 == v6 || v9 == v8 )
        {
          _list_add_valid_or_report(v8, v1 + 160);
        }
        else
        {
          v9[1] = v8;
          *v8 = v9;
          v8[1] = v6;
          *v6 = v8;
        }
      }
      v5 = of_get_next_available_child(*(_QWORD *)(a1 + 744), v5);
      if ( !v5 )
        goto LABEL_16;
    }
    kfree(v8);
  }
  if ( string != -17 )
LABEL_20:
    dev_err(a1, "failed to alloc items ret = %d\n", string);
  return string;
}
