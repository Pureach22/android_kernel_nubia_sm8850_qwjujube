__int64 __fastcall sde_debugfs_timeline_dump(__int64 a1, unsigned int *a2, __int64 *a3)
{
  unsigned int v3; // w4
  const char *v5; // x8
  __int64 v6; // x0
  const char *v8; // x2
  _QWORD *v9; // x25
  __int64 v10; // x6
  _QWORD *v11; // x28
  _QWORD *v12; // x23
  __int64 v13; // x8
  _DWORD *v14; // x9
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x22
  const char *v17; // x24
  __int64 (__fastcall *v18)(_QWORD); // x8
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x25
  const char *v22; // x26
  __int64 (__fastcall *v23)(_QWORD); // x8
  __int64 result; // x0
  _QWORD v25[17]; // [xsp+8h] [xbp-88h] BYREF

  v25[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v3 = a2[1];
    v5 = "unknown";
    v6 = *a3;
    if ( v3 == -1061109568 )
      v5 = "connector";
    if ( v3 == -858993460 )
      v8 = "crtc";
    else
      v8 = v5;
    seq_printf(v6, "drm obj:%s id:%d type:0x%x done_count:%d commit_count:%d\n", v8, *a2);
    raw_spin_lock(a1 + 20);
    v9 = *(_QWORD **)(a1 + 48);
    if ( v9 != (_QWORD *)(a1 + 48) )
    {
      do
      {
        v11 = (_QWORD *)*v9;
        v12 = v9 - 12;
        memset(v25, 0, 128);
        v13 = *(v9 - 11);
        v14 = *(_DWORD **)(v13 + 64);
        if ( v14 )
        {
          if ( *(v14 - 1) != -938580849 )
            __break(0x8229u);
          ((void (__fastcall *)(_QWORD *, _QWORD *, __int64))v14)(v9 - 12, v25, 128);
          v13 = *(v9 - 11);
        }
        v15 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
        v16 = *a3;
        if ( *((_DWORD *)v15 - 1) != -352706110 )
          __break(0x8228u);
        v17 = (const char *)v15(v9 - 12);
        v18 = *(__int64 (__fastcall **)(_QWORD))(*(v9 - 11) + 16LL);
        if ( *((_DWORD *)v18 - 1) != -352706110 )
          __break(0x8228u);
        v19 = v18(v9 - 12);
        v20 = *(v9 - 11);
        v21 = *(v9 - 7);
        v22 = (const char *)v19;
        v23 = *(__int64 (__fastcall **)(_QWORD))(v20 + 32);
        if ( v23 )
        {
          if ( *((_DWORD *)v23 - 1) != 1879296680 )
            __break(0x8228u);
          v10 = v23(v12) & 1;
        }
        else
        {
          LODWORD(v10) = -1;
        }
        seq_printf(
          v16,
          "fence name:%s timeline name:%s seqno:0x%llx timeline:%s signaled:0x%x\n",
          v17,
          v22,
          v21,
          (const char *)v25,
          v10);
        v9 = v11;
      }
      while ( v11 != (_QWORD *)(a1 + 48) );
    }
    result = raw_spin_unlock(a1 + 20);
  }
  else
  {
    result = printk(&unk_21DA28, "sde_debugfs_timeline_dump");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
