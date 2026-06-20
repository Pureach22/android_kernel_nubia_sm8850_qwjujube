__int64 __fastcall cam_vfe_bus_deinit_hw(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x21
  unsigned int v4; // w0
  unsigned int v5; // w21
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x8
  __int64 v9; // x0
  _QWORD *v10; // x1

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_deinit_hw",
      3622,
      "Error: Invalid args");
    return 4294967274LL;
  }
  v2 = a1 + 33512;
  if ( *(_BYTE *)(a1 + 33608) != 1 )
    return 0;
  v3 = (_DWORD *)(a1 + 42648);
  if ( *(_DWORD *)(a1 + 42652) )
  {
    v4 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 24));
    *(_DWORD *)(a1 + 42652) = 0;
    if ( !*v3 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v4 = 0;
  if ( *v3 )
  {
LABEL_5:
    v4 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 32));
    *v3 = 0;
  }
LABEL_6:
  v5 = v4;
  v6 = raw_spin_lock_irqsave(a1 + 33528);
  v7 = 0;
  *(_QWORD *)v2 = v2;
  *(_QWORD *)(v2 + 8) = v2;
  do
  {
    v8 = a1 + v7;
    v9 = v8 + 744;
    *(_QWORD *)(v8 + 744) = v8 + 744;
    *(_QWORD *)(v8 + 752) = v8 + 744;
    v10 = *(_QWORD **)(v2 + 8);
    if ( (_QWORD *)(a1 + v7 + 744) == v10 || *v10 != v2 )
    {
      _list_add_valid_or_report(v9);
    }
    else
    {
      *(_QWORD *)(v2 + 8) = v9;
      *(_QWORD *)(v8 + 744) = v2;
      *(_QWORD *)(v8 + 752) = v10;
      *v10 = v9;
    }
    v7 += 128;
  }
  while ( v7 != 0x8000 );
  *(_BYTE *)(v2 + 96) = 0;
  raw_spin_unlock_irqrestore(a1 + 33528, v6);
  return v5;
}
