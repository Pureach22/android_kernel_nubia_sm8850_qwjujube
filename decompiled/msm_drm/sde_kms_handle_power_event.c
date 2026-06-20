__int64 __fastcall sde_kms_handle_power_event(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int v9; // w20
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 v15; // x8
  __int64 (*v16)(void); // x9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  void (*v20)(void); // x8
  int v21; // w20
  int v22; // w7
  __int64 v23; // x4
  char v24; // [xsp+0h] [xbp+0h]
  char v25; // [xsp+0h] [xbp+0h]

  if ( !a2 || !*(_QWORD *)(a2 + 136) )
    return result;
  v9 = result;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "event_type:%d\n", result);
  result = sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_handle_power_event", 5409, 4, v9, -1059143953, a7, a8, v24);
  v10 = *(_QWORD *)(*(_QWORD *)(a2 + 136) + 56LL);
  if ( v10 )
  {
    if ( *(_DWORD *)(v10 + 5912) == 1 )
      return result;
    if ( v9 != 1 )
      goto LABEL_8;
  }
  else
  {
    result = printk(&unk_25E374, "sde_kms_get_disp_op");
    if ( v9 != 1 )
    {
LABEL_8:
      if ( v9 != 8 )
        return result;
      sde_irq_update(a2, 1);
      v11 = *(_QWORD *)(a2 + 3552);
      *(_BYTE *)(a2 + 3744) = 1;
      if ( v11 )
      {
        v12 = *(_QWORD *)(a2 + 152);
        if ( !v12 || (*(_BYTE *)(v12 + 20120) & 1) == 0 )
          sde_hw_set_rotator_sid();
      }
      result = *(_QWORD *)(a2 + 3528);
      if ( !result )
        goto LABEL_19;
      v13 = *(unsigned int *)(result + 28);
      if ( (unsigned int)v13 < 3 )
      {
        v14 = *(__int64 (**)(void))(result + 8 * v13 + 368);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != -1678686942 )
            __break(0x8228u);
          result = v14();
        }
LABEL_19:
        if ( !*(_DWORD *)(a2 + 2544) )
        {
          v15 = *(_QWORD *)(a2 + 152);
          if ( !v15 || (*(_BYTE *)(v15 + 20120) & 1) == 0 )
          {
            sde_vbif_init_memtypes(a2);
            sde_kms_init_shared_hw(a2);
            sde_kms_set_lutdma_vbif_remap(a2);
            result = *(_QWORD *)(a2 + 3544);
            if ( result )
            {
              if ( *(_QWORD *)(a2 + 152) )
              {
                v16 = *(__int64 (**)(void))(result + 1656);
                if ( v16 )
                {
                  if ( *((_DWORD *)v16 - 1) != -1646250321 )
                    __break(0x8229u);
                  return v16();
                }
              }
            }
          }
        }
        return result;
      }
LABEL_40:
      __break(0x5512u);
      return ((__int64 (*)(void))sde_kms_init_shared_hw)();
    }
  }
  result = sde_irq_update(a2, 0);
  v17 = *(_QWORD *)(a2 + 152);
  *(_BYTE *)(a2 + 3744) = 0;
  if ( v17 && (*(_BYTE *)(v17 + 20120) & 1) != 0 )
    return result;
  v18 = *(_QWORD *)(a2 + 3536);
  if ( v18 )
  {
    v19 = *(unsigned int *)(v18 + 28);
    if ( (unsigned int)v19 >= 3 )
      goto LABEL_40;
    v20 = *(void (**)(void))(v18 + 8 * v19 + 184);
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != 193872765 )
        __break(0x8228u);
      v20();
    }
  }
  result = ((__int64 (__fastcall *)(__int64))sde_vbif_axi_halt_request)(a2);
  if ( (_DWORD)result )
  {
    v21 = result;
    printk(&unk_235444, "sde_kms_handle_power_event");
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_handle_power_event", 5444, -1, v21, 60333, -1059143953, v22, v25);
    return sde_dbg_dump(2, "sde_kms_handle_power_event", 0xFFFFFF, 0, v23);
  }
  return result;
}
