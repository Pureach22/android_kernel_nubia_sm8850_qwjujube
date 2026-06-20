__int64 __fastcall btfm_slim_enable_ch(__int64 a1, __int64 a2, unsigned int a3, int a4, unsigned __int8 a5)
{
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x2
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int chipset_version; // w0
  unsigned int v17; // w0
  __int64 v18; // x23
  unsigned __int8 *v19; // x24
  __int64 v20; // x22
  __int16 v21; // t1
  _DWORD *v22; // x8
  __int64 v23; // x1
  void *v24; // x8
  unsigned int v25; // w20

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v11 = slim_stream_allocate(*(_QWORD *)(a1 + 8), "BTFM_SLIM");
    *(_QWORD *)(a2 + 64) = v11;
    if ( !v11 )
    {
      printk(&unk_8154, "btfm_slim_enable_ch", v12);
      return 4294967274LL;
    }
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(a1 + 1088);
    v13 = *(unsigned __int16 *)(a1 + 1092);
    *(_DWORD *)(a2 + 24) = a4;
    *(_DWORD *)(a2 + 32) = a5;
    *(_DWORD *)(a2 + 56) = v13;
    v14 = _kmalloc_noprof(4LL * a5, 3520);
    *(_QWORD *)(a2 + 40) = v14;
    if ( v14 )
    {
      if ( a5 )
      {
        v18 = 0;
        v19 = (unsigned __int8 *)(a2 + 16);
        v20 = 4LL * a5;
        while ( 1 )
        {
          v22 = *(_DWORD **)(a1 + 1120);
          if ( v22 )
          {
            v23 = *v19;
            if ( *(v22 - 1) != -1491053558 )
              __break(0x8228u);
            v17 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v22)(a1, v23, a3, 1);
            if ( (v17 & 0x80000000) != 0 )
              break;
          }
          *(_DWORD *)(*(_QWORD *)(a2 + 40) + v18) = v19[2];
          v18 += 4;
          v21 = *(_WORD *)v19;
          v19 += 72;
          *(_QWORD *)(a2 + 48) |= 1LL << v21;
          if ( v20 == v18 )
            goto LABEL_9;
        }
        v24 = &unk_8E6B;
      }
      else
      {
LABEL_9:
        v15 = printk(&unk_81E2, "btfm_slim_enable_ch", *(unsigned __int16 *)(a2 + 16));
        chipset_version = btpower_get_chipset_version(v15);
        printk(&unk_87EC, "btfm_slim_enable_ch", chipset_version);
        if ( btfm_feedback_ch_setting )
          btfm_feedback_ch_setting = 0;
        v17 = slim_stream_prepare(*(_QWORD *)(a2 + 64), a2 + 24);
        if ( v17 )
        {
          v24 = &unk_85FE;
        }
        else
        {
          v17 = slim_stream_enable(*(_QWORD *)(a2 + 64));
          if ( !v17 )
          {
            printk(&unk_824A, "btfm_slim_enable_ch", (unsigned int)++btfm_num_ports_open);
            return 0;
          }
          v24 = &unk_8E90;
        }
      }
      v25 = v17;
      printk(v24, "btfm_slim_enable_ch", v17);
      printk(&unk_8354, "btfm_slim_enable_ch", v25);
      kfree(*(_QWORD *)(a2 + 40));
      *(_QWORD *)(a2 + 40) = 0;
      return v25;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
