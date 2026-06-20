__int64 __fastcall sde_crtc_vblank_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x23
  unsigned int v5; // w22
  __int64 v8; // x0
  _QWORD *v9; // x21
  __int64 v10; // x9
  _QWORD *v11; // x8
  __int64 v12; // x10
  __int64 v13; // x0
  __int64 v14; // x8
  int v15; // w7
  void *v16; // x0
  char v17; // [xsp+0h] [xbp+0h]

  if ( !a1 || !*(_QWORD *)a1 || (v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v16 = &unk_25E167;
LABEL_19:
    printk(v16, "_sde_crtc_get_kms");
    return printk(&unk_248EC7, "sde_crtc_vblank_cb");
  }
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
  {
    v16 = &unk_234896;
    goto LABEL_19;
  }
  v5 = *(_DWORD *)(a1 + 160);
  if ( (*(_QWORD *)(*(_QWORD *)(v4 + 152) + 22008LL) & 0x1000000) == 0 )
    return sde_crtc_vblank_notify(a1);
  v8 = raw_spin_lock_irqsave(a1 + 6036);
  v9 = *(_QWORD **)(a1 + 6016);
  v10 = v8;
  if ( v9 == (_QWORD *)(a1 + 6016) || v9 == &_ksymtab_dss_reg_dump )
  {
    raw_spin_unlock_irqrestore(a1 + 6036, v8);
    if ( (unsigned int)__ratelimit(&sde_crtc_vblank_cb__rs, "sde_crtc_vblank_cb") )
      printk(&unk_26FE33, "sde_crtc_vblank_cb");
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_crtc_vblank_cb",
             3595,
             -1,
             *(_DWORD *)(a1 + 112),
             60333,
             -1059143953,
             v15,
             v17);
  }
  else
  {
    v11 = (_QWORD *)v9[1];
    if ( (_QWORD *)*v11 == v9 && (v12 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
    {
      *(_QWORD *)(v12 + 8) = v11;
      *v11 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 6016));
    }
    *v9 = v9;
    v9[1] = v9;
    v13 = raw_spin_unlock_irqrestore(a1 + 6036, v10);
    v14 = *(_QWORD *)(*(_QWORD *)(v4 + 136) + 56LL);
    v9[2] = a2;
    *(v9 - 1) = a1;
    if ( v5 >= 0x10 )
    {
      __break(0x5512u);
      return sde_crtc_vblank_notify(v13);
    }
    else
    {
      return kthread_queue_work(v14 + 80LL * v5 + 2432, v9 - 6);
    }
  }
}
