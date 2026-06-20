__int64 __fastcall sde_vm_request_valid(__int64 a1, int a2, unsigned int a3)
{
  __int64 v5; // x8
  __int64 (*v6)(void); // x8
  __int64 v7; // x22
  char v8; // w21
  bool v9; // zf
  unsigned int v10; // w22
  __int64 v11; // x8

  if ( a1 && (v5 = *(_QWORD *)(a1 + 6384)) != 0 && (v6 = *(__int64 (**)(void))(v5 + 88)) != nullptr )
  {
    v7 = a1;
    if ( *((_DWORD *)v6 - 1) != 1370937740 )
      __break(0x8228u);
    v8 = v6();
    a1 = v7;
    v9 = a3 == 2;
    if ( a3 >= 2 )
    {
LABEL_7:
      if ( !v9 )
      {
        printk(&unk_21494F, "sde_vm_request_valid");
LABEL_21:
        v10 = -22;
        goto LABEL_22;
      }
      if ( a2 == 1 )
      {
        if ( (v8 & 1) == 0 )
          goto LABEL_20;
      }
      else if ( a2 != 2 )
      {
        goto LABEL_21;
      }
      if ( !a1 )
        goto LABEL_21;
      v11 = *(_QWORD *)(a1 + 152);
      if ( !v11 || (*(_BYTE *)(v11 + 20120) & 1) == 0 )
        goto LABEL_21;
LABEL_20:
      v10 = 0;
      goto LABEL_22;
    }
  }
  else
  {
    v8 = 1;
    v9 = a3 == 2;
    if ( a3 >= 2 )
      goto LABEL_7;
  }
  if ( ((a2 != 1) & (unsigned __int8)v8) != 0 )
    v10 = 0;
  else
    v10 = -22;
LABEL_22:
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "old req: %d new req: %d owns_hw: %d, rc: %d\n", a2, a3, v8 & 1, v10);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_vm_request_valid", 339, -1, a2, a3, v8 & 1, v10, 239);
  return v10;
}
