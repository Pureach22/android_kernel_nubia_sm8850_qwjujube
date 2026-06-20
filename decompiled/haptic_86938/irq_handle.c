__int64 __fastcall irq_handle(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 (__fastcall *v4)(_QWORD); // x8
  int v5; // w0
  _DWORD *v6; // x8
  unsigned __int8 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x8
  _DWORD *v9; // x12
  __int64 v10; // x1
  unsigned int v11; // w20
  __int64 v12; // x9
  __int64 (__fastcall *v13)(_QWORD); // x8
  char v14; // w0
  int v15; // w8
  unsigned __int8 (__fastcall *v16)(_QWORD); // x8
  __int64 i; // x1
  unsigned __int8 (__fastcall *v18)(_QWORD); // x8
  void *v19; // x0
  __int64 v20; // x2
  void *v21; // x0
  __int64 v22; // x2
  __int64 v23; // x8
  _DWORD *v24; // x8
  _DWORD *v25; // x8

  printk(&unk_14A18, "haptic_hv", 1637, "irq_handle");
  v3 = *(_DWORD *)(a2 + 1724);
  v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 1480) + 24LL);
  if ( *((_DWORD *)v4 - 1) != 1361900016 )
    __break(0x8228u);
  v5 = v4(a2);
  if ( v3 == 1 )
  {
    if ( !v5 )
    {
      printk(&unk_1680C, "haptic_hv", 1642, "irq_handle");
      for ( i = *(_DWORD *)(a2 + 1112) >> 1; ; i = *(_DWORD *)(a2 + 1112) >> 2 )
      {
        richtap_update_fifo_data(a2, i);
        v18 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 1480) + 384LL);
        if ( *((_DWORD *)v18 - 1) != 2018195540 )
          __break(0x8228u);
        if ( v18(a2) || !*(_DWORD *)(a2 + 1724) || **(_BYTE **)(a2 + 1568) != 85 )
          break;
      }
    }
    if ( **(unsigned __int8 **)(a2 + 1568) == 255 )
    {
      printk(&unk_15555, "haptic_hv", 1653, "irq_handle");
      v6 = *(_DWORD **)(*(_QWORD *)(a2 + 1480) + 272LL);
      if ( *(v6 - 1) != 487251822 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v6)(a2, 0);
      *(_DWORD *)(a2 + 1724) = 0;
    }
  }
  else
  {
    if ( !v5 )
    {
      if ( *(_BYTE *)(a2 + 5) == 1 )
      {
        v7 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 1480) + 368LL);
        if ( *((_DWORD *)v7 - 1) != 2018195540 )
          __break(0x8228u);
        if ( !v7(a2) )
        {
          while ( 1 )
          {
            if ( *(_BYTE *)(a2 + 23) != 2 )
              goto LABEL_48;
            mutex_lock(a2 + 880);
            v8 = *(unsigned int *)(a2 + 116);
            if ( !(_DWORD)v8 )
              break;
            if ( !aw_rtp )
            {
              v19 = &unk_15BBB;
              v20 = 1677;
              goto LABEL_40;
            }
            v9 = *(_DWORD **)(*(_QWORD *)(a2 + 1480) + 208LL);
            v10 = aw_rtp + v8 + 4;
            if ( (unsigned int)(*(_DWORD *)aw_rtp - v8) >= *(_DWORD *)(a2 + 1112) >> 2 )
              v11 = *(_DWORD *)(a2 + 1112) >> 2;
            else
              v11 = *(_DWORD *)aw_rtp - v8;
            if ( *(v9 - 1) != -962088293 )
              __break(0x822Cu);
            ((void (__fastcall *)(__int64, __int64, _QWORD))v9)(a2, v10, v11);
            v12 = *(_QWORD *)(a2 + 1480);
            *(_DWORD *)(a2 + 116) += v11;
            v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 352);
            if ( *((_DWORD *)v13 - 1) != 2018195540 )
              __break(0x8228u);
            v14 = v13(a2);
            v15 = *(_DWORD *)(a2 + 116);
            if ( v15 == *(_DWORD *)aw_rtp || (v14 & 0xF) == 0 )
            {
              if ( v15 == *(_DWORD *)aw_rtp )
              {
                v21 = &unk_16B25;
                v22 = 1704;
              }
              else
              {
                v21 = &unk_15EB5;
                v22 = 1701;
              }
              printk(v21, "haptic_hv", v22, "irq_handle");
              v23 = *(_QWORD *)(a2 + 1480);
              *(_BYTE *)(a2 + 29) = 0;
              v24 = *(_DWORD **)(v23 + 272);
              if ( *(v24 - 1) != 487251822 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD))v24)(a2, 0);
              *(_DWORD *)(a2 + 116) = 0;
              *(_BYTE *)(a2 + 5) = 0;
              goto LABEL_47;
            }
            mutex_unlock(a2 + 880);
            v16 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 1480) + 368LL);
            if ( *((_DWORD *)v16 - 1) != 2018195540 )
              __break(0x8228u);
            if ( v16(a2) )
              goto LABEL_48;
          }
          v19 = &unk_15583;
          v20 = 1668;
LABEL_40:
          printk(v19, "haptic_hv", v20, "irq_handle");
LABEL_47:
          mutex_unlock(a2 + 880);
        }
      }
      else
      {
        printk(&unk_165F4, "haptic_hv", 1717, "irq_handle");
      }
    }
LABEL_48:
    if ( *(_BYTE *)(a2 + 23) != 2 )
    {
      v25 = *(_DWORD **)(*(_QWORD *)(a2 + 1480) + 272LL);
      if ( *(v25 - 1) != 487251822 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v25)(a2, 0);
    }
  }
  return 1;
}
