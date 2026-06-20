__int64 __fastcall venus_hfi_set_ir_period(__int64 a1, int a2, unsigned int a3)
{
  __int64 v6; // x19
  __int64 v7; // x4
  __int64 v8; // x0
  int v9; // w3
  unsigned int v10; // w1
  int v11; // w2
  int v12; // w24
  unsigned int header; // w23
  unsigned int *v14; // x23
  unsigned int v15; // w24
  int v16; // w0
  int v17; // w6
  unsigned int *v18; // x23
  unsigned int v19; // w24
  int port_info; // w0
  int v21; // w6
  __int64 v22; // x22
  __int64 v23; // x24
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x4
  int v29; // [xsp+10h] [xbp-10h] BYREF
  int v30; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 320);
  v30 = 0;
  v29 = 0;
  core_lock(v6);
  v8 = *(_QWORD *)(a1 + 368);
  if ( !v8 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8DDBA, "err ", a1 + 340, "venus_hfi_set_ir_period", v7);
    header = -22;
    goto LABEL_18;
  }
  if ( a3 < 0xC6 )
  {
    v9 = *(_DWORD *)(v6 + 6600);
    v10 = *(_DWORD *)(a1 + 376);
    v11 = *(_DWORD *)(a1 + 332);
    v12 = *(_DWORD *)(a1 + 168LL * a3 + 4352);
    *(_DWORD *)(v6 + 6600) = v9 + 1;
    v30 = v12;
    header = hfi_create_header(v8, v10, v11, v9);
    if ( !header )
    {
      if ( (*(_BYTE *)(a1 + 38705) & 1) != 0 )
        goto LABEL_8;
      *(_BYTE *)(a1 + 38705) = v12 != 0;
      if ( !v12
        || (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) == 0
        || (v14 = *(unsigned int **)(a1 + 368),
            v15 = *(_DWORD *)(a1 + 376),
            v29 = 2,
            v16 = msm_vidc_get_port_info(a1, 0x76u),
            v17 = *(_DWORD *)(v6 + 6604),
            *(_DWORD *)(v6 + 6604) = v17 + 1,
            (header = hfi_create_packet(v14, v15, 50331973, 0, 9, v16, v17, &v29, 4u)) == 0) )
      {
LABEL_8:
        v18 = *(unsigned int **)(a1 + 368);
        v19 = *(_DWORD *)(a1 + 376);
        port_info = msm_vidc_get_port_info(a1, a3);
        v21 = *(_DWORD *)(v6 + 6604);
        *(_DWORD *)(v6 + 6604) = v21 + 1;
        header = hfi_create_packet(v18, v19, a2, 0, 1, port_info, v21, &v30, 4u);
        if ( !header )
        {
          v22 = *(_QWORD *)(a1 + 320);
          v23 = *(_QWORD *)(a1 + 368);
          header = _resume(v22);
          if ( header || (header = venus_hfi_queue_cmd_write(v22, v23)) != 0 )
          {
            if ( a1 )
            {
              if ( (msm_vidc_debug & 1) != 0 )
              {
                cap_name(a3);
                printk(&unk_8A0FA, "err ", a1 + 340, "venus_hfi_set_ir_period", a3);
              }
            }
          }
          else
          {
            _schedule_power_collapse_work(v22, v24, v25, v26, v27);
          }
        }
      }
    }
LABEL_18:
    core_unlock(v6);
    _ReadStatusReg(SP_EL0);
    return header;
  }
  __break(0x5512u);
  return venus_hfi_get_device_region_info();
}
