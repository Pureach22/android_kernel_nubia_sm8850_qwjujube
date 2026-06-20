__int64 __fastcall btfm_slim_disable_ch(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  unsigned int v4; // w20
  __int64 v5; // x19
  int v9; // w23
  __int64 v10; // x2
  int v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w0
  int v14; // w8
  unsigned int v15; // w0
  __int64 v16; // x2
  _DWORD *v17; // x8
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 v21; // x2
  __int64 v22; // x0
  int chipset_version; // w0
  __int64 v24; // x2
  unsigned __int16 v25; // w8
  int v26; // w8

  v4 = -22;
  if ( a1 )
  {
    v5 = a2;
    if ( a2 )
    {
      LOBYTE(v9) = a4;
      printk(&unk_8CA1, "btfm_slim_disable_ch", *(unsigned __int16 *)(a2 + 16));
      if ( !*(_QWORD *)(v5 + 64) )
      {
        printk(&unk_8EB6, "btfm_slim_disable_ch", v10);
        return v4;
      }
      if ( (_BYTE)a3 )
      {
        v11 = *(_DWORD *)(a1 + 1084);
        if ( v11 == 88200 || v11 == 44100 )
        {
          printk(&unk_8B30, "btfm_slim_disable_ch", v10);
          v12 = slim_stream_unprepare_disconnect_port(*(_QWORD *)(v5 + 64), 1, 0);
          if ( v12 )
            printk(&unk_8A77, "btfm_slim_disable_ch", v12);
        }
      }
      v13 = slim_stream_disable(*(_QWORD *)(v5 + 64));
      if ( v13 )
      {
        printk(&unk_842B, "btfm_slim_disable_ch", v13);
        v14 = *(_DWORD *)(a1 + 1084);
        if ( v14 != 44100 && v14 != 88200 )
        {
          v15 = slim_stream_unprepare_disconnect_port(*(_QWORD *)(v5 + 64), 1, 0);
          if ( v15 )
            printk(&unk_8A77, "btfm_slim_disable_ch", v15);
        }
      }
      v4 = slim_stream_unprepare_disconnect_port(*(_QWORD *)(v5 + 64), 0, 1);
      if ( v4 )
        printk(&unk_8894, "btfm_slim_disable_ch", v4);
      v9 = (unsigned __int8)v9;
      if ( (_BYTE)v9 )
      {
        while ( 1 )
        {
          v17 = *(_DWORD **)(a1 + 1120);
          if ( v17 )
          {
            v18 = *(unsigned __int8 *)(v5 + 16);
            if ( *(v17 - 1) != -1491053558 )
              __break(0x8228u);
            v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v17)(a1, v18, a3, 0);
            if ( (v4 & 0x80000000) != 0 )
              break;
          }
          --v9;
          v5 += 72;
          if ( !v9 )
            goto LABEL_26;
        }
        printk(&unk_880A, "btfm_slim_disable_ch", v4);
      }
LABEL_26:
      v19 = *(_QWORD *)(v5 + 40);
      *(_QWORD *)(v5 + 48) = 0;
      if ( v19 )
      {
        kfree(v19);
        printk(&unk_8A9E, "btfm_slim_disable_ch", v20);
        *(_QWORD *)(v5 + 40) = 0;
      }
      else
      {
        printk(&unk_8525, "btfm_slim_disable_ch", v16);
      }
      v21 = (unsigned int)btfm_num_ports_open;
      if ( btfm_num_ports_open >= 1 )
        v21 = (unsigned int)--btfm_num_ports_open;
      *(_QWORD *)(v5 + 64) = 0;
      v22 = printk(&unk_824A, "btfm_slim_disable_ch", v21);
      chipset_version = btpower_get_chipset_version(v22);
      if ( !btfm_num_ports_open )
      {
        if ( chipset_version > 1075052799 )
        {
          if ( (unsigned int)(chipset_version - 1075052800) <= 0x20 && ((1LL << chipset_version) & 0x100010001LL) != 0
            || (unsigned int)(chipset_version - 1075249408) < 2 )
          {
            goto LABEL_48;
          }
          v26 = 1075249664;
          goto LABEL_47;
        }
        if ( chipset_version > 1074528767 )
        {
          if ( chipset_version > 1074532864 )
          {
            if ( chipset_version == 1074532865 )
              goto LABEL_48;
            v25 = 4625;
          }
          else
          {
            if ( chipset_version == 1074528768 )
              goto LABEL_48;
            v25 = 528;
          }
          v26 = v25 | 0x400C0000;
LABEL_47:
          if ( chipset_version != v26 )
            return v4;
LABEL_48:
          printk(&unk_845F, "btfm_slim_disable_ch", v24);
          msleep(200);
          return v4;
        }
        if ( (unsigned int)(chipset_version - 1073873184) <= 0x30
          && ((1LL << ((unsigned __int8)chipset_version - 32)) & 0x1000000010001LL) != 0 )
        {
          goto LABEL_48;
        }
      }
    }
  }
  return v4;
}
