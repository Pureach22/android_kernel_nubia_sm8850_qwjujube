__int64 __fastcall msm_ext_disp_audio_notify(__int64 a1, unsigned int *a2, unsigned int a3)
{
  unsigned __int64 v4; // x19
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x21
  int v9; // w20
  void *v10; // x0
  __int64 v12; // x0

  if ( !a1 )
  {
    v10 = &unk_71BD;
    goto LABEL_20;
  }
  if ( !a2 || *a2 == -1 || a2[1] > 1 || (int)a2[2] >= 2 )
  {
    v10 = &unk_6F91;
LABEL_20:
    printk(v10, "msm_ext_disp_validate_and_get");
    goto LABEL_21;
  }
  if ( a3 >= 2 )
  {
    printk(&unk_700C, "msm_ext_disp_validate_and_get");
LABEL_21:
    LODWORD(v4) = -22;
    return (unsigned int)v4;
  }
  v4 = *(_QWORD *)(a1 + 168);
  if ( !v4 )
  {
    v10 = &unk_702A;
    goto LABEL_20;
  }
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)v4;
  v6 = mutex_lock(v4 + 88);
  if ( !*(_QWORD *)(v4 + 40) )
  {
    printk(&unk_6EE0, "msm_ext_disp_process_audio");
    v9 = -1;
LABEL_16:
    mutex_unlock(v4 + 88);
    LODWORD(v4) = v9;
    return (unsigned int)v4;
  }
  v7 = a2[2];
  if ( (unsigned int)v7 < 2 )
  {
    v8 = *(_QWORD *)(v4 + 8 * v7 + 48);
    if ( (unsigned int)extcon_get_state(v8, *a2) == a3 )
    {
      v9 = -17;
    }
    else
    {
      v9 = extcon_set_state_sync(v8, *a2, a3 != 0);
      if ( v9 )
        printk(&unk_70D8, "msm_ext_disp_process_audio");
    }
    goto LABEL_16;
  }
  __break(0x5512u);
  v12 = MEMORY[0x69DA90C](v6);
  return msm_ext_disp_deregister_intf(v12);
}
