__int64 __fastcall venus_hfi_core_deinit(__int64 a1, char a2)
{
  bool v4; // w8
  __int64 result; // x0
  __int64 v6; // x1
  __int64 v7; // x4
  int v8; // w3
  __int64 v9; // x0
  unsigned int v10; // w1
  __int64 v11; // x8
  int v12; // w9
  unsigned __int64 v13; // x11
  unsigned __int64 v14; // x25
  __int64 v15; // x20
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x8
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x25
  __int64 v23; // x8
  _DWORD *v24; // x8
  int v25; // w9
  int v26; // w6
  unsigned int *v27; // x0
  unsigned int v28; // w1
  _DWORD *v29; // x8
  int v30; // w5
  _QWORD v31[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  int v35; // [xsp+30h] [xbp-20h]
  int v36; // [xsp+34h] [xbp-1Ch]
  __int64 v37; // [xsp+38h] [xbp-18h]
  __int64 v38; // [xsp+40h] [xbp-10h]
  __int64 v39; // [xsp+48h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8A0CF, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_core_deinit");
  if ( (mutex_is_locked(a1 + 3856) & 1) != 0 )
  {
    v4 = is_core_state(a1, 0);
    result = 0;
    if ( !v4 )
    {
      if ( *(_BYTE *)(a1 + 4768) == 1 )
      {
        if ( *(_BYTE *)(a1 + 4769) == 1 && *(_BYTE *)(a1 + 4770) == 1 )
        {
          *(_WORD *)(a1 + 4769) = 0;
          msm_vidc_change_core_sub_state(a1, 0xFFu, 0, (__int64)"venus_hfi_core_deinit");
          msm_vidc_change_core_state(a1, 0, (__int64)"venus_hfi_core_deinit");
        }
LABEL_31:
        result = 0;
        goto LABEL_32;
      }
      _resume(a1);
      if ( (a2 & 1) != 0 )
        v6 = 0;
      else
        v6 = *(_QWORD *)(a1 + 6464);
      _flush_debug_queue(a1, v6, *(unsigned int *)(a1 + 6472));
      if ( (msm_vidc_syscache_disable & 1) != 0 || !*(_DWORD *)(*(_QWORD *)(a1 + 3912) + 120LL) )
        goto LABEL_23;
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 3904) + 108LL) & 1) == 0 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_967C3, "high", 0xFFFFFFFFLL, "codec", v7);
        goto LABEL_23;
      }
      v8 = *(_DWORD *)(a1 + 6600);
      v9 = *(_QWORD *)(a1 + 6464);
      v10 = *(_DWORD *)(a1 + 6472);
      *(_DWORD *)(a1 + 6600) = v8 + 1;
      if ( (unsigned int)hfi_create_header(v9, v10, 0, v8) )
      {
LABEL_23:
        if ( a1 )
        {
          v23 = *(_QWORD *)(a1 + 6552);
          if ( v23 )
          {
            v24 = *(_DWORD **)(v23 + 88);
            if ( v24 )
            {
              if ( *(v24 - 1) != -254569353 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD))v24)(a1, 0);
            }
          }
        }
        _unload_fw(a1);
        if ( msm_vidc_fw_dump == 1 )
          fw_coredump((__int64 *)a1);
        goto LABEL_31;
      }
      v11 = *(_QWORD *)(a1 + 3904);
      v31[0] = 0;
      v31[1] = 0;
      v37 = 0;
      v38 = 0;
      v12 = *(_DWORD *)(v11 + 104);
      v13 = *(_QWORD *)(v11 + 96);
      v34 = 0;
      v36 = 0;
      v32 = 0;
      v33 = 0;
      v14 = v13 + 24LL * (unsigned int)(v12 - 1);
      LODWORD(v31[0]) = 4;
      v35 = 1;
      if ( v14 < v13 )
      {
LABEL_17:
        v15 = *(_QWORD *)(a1 + 6464);
        if ( !(unsigned int)_resume(a1) && !(unsigned int)venus_hfi_queue_cmd_write(a1, v15) )
        {
          _schedule_power_collapse_work(a1, v16, v17, v18, v19);
          v20 = *(_QWORD *)(a1 + 3904);
          v21 = *(_QWORD *)(v20 + 96);
          v22 = v21 + 24LL * (unsigned int)(*(_DWORD *)(v20 + 104) - 1);
          if ( v22 >= v21 )
          {
            do
            {
              if ( *(_BYTE *)(v22 + 20) == 1 && (msm_vidc_debug & 2) != 0 )
              {
                printk(&unk_81AC9, "high", 0xFFFFFFFFLL, "codec", "__release_subcaches");
                v20 = *(_QWORD *)(a1 + 3904);
              }
              v22 -= 24LL;
            }
            while ( v22 >= *(_QWORD *)(v20 + 96) );
          }
          *(_BYTE *)(v20 + 108) = 0;
        }
        goto LABEL_23;
      }
      while ( *(_BYTE *)(v14 + 20) != 1 )
      {
LABEL_37:
        v14 -= 24LL;
        if ( v14 < *(_QWORD *)(v11 + 96) )
          goto LABEL_17;
      }
      v29 = *(_DWORD **)v14;
      v30 = *(_DWORD *)(v14 + 16);
      HIDWORD(v31[0]) = **(_DWORD **)v14;
      if ( v30 > 69 )
      {
        if ( v30 == 70 )
        {
          v25 = 4;
LABEL_35:
          v36 = v25;
          v26 = *(_DWORD *)(a1 + 6604);
          v27 = *(unsigned int **)(a1 + 6464);
          v28 = *(_DWORD *)(a1 + 6472);
          HIDWORD(v32) = *((_QWORD *)v29 + 1);
          *(_DWORD *)(a1 + 6604) = v26 + 1;
          if ( (unsigned int)hfi_create_packet(v27, v28, 16777225, 0, 5, 0, v26, v31, 0x40u) )
            goto LABEL_23;
          v11 = *(_QWORD *)(a1 + 3904);
          goto LABEL_37;
        }
        if ( v30 == 83 )
        {
          v25 = 5;
          goto LABEL_35;
        }
      }
      else
      {
        if ( v30 == 2 )
        {
          v25 = 1;
          goto LABEL_35;
        }
        if ( v30 == 64 )
        {
          v25 = 2;
          goto LABEL_35;
        }
      }
      if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_82E2B, "err ", 0xFFFFFFFFLL, "codec", "__get_hfi_subcache_type");
        v29 = *(_DWORD **)v14;
      }
      v25 = 0;
      goto LABEL_35;
    }
  }
  else
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_core_deinit");
    result = 4294967274LL;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
