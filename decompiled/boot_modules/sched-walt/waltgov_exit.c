__int64 __fastcall waltgov_exit(__int64 a1)
{
  _QWORD *v1; // x22
  char *v2; // x23
  _QWORD *v3; // x20
  __int64 v5; // x21
  int v6; // w0
  __int64 v7; // x8
  __int64 v8; // x0
  char v10; // w9
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  __int64 v13; // x10
  bool v14; // cf
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x25
  __int64 v17; // x0

  v3 = *(_QWORD **)(a1 + 88);
  v5 = v3[5];
  v6 = gov_attr_set_put(v5, v3 + 6);
  *(_QWORD *)(a1 + 88) = 0;
  if ( !v6 )
  {
    v7 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v7 >= 0x20 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(StatusReg + 80);
      v17 = _tracepoint_android_rvh_sched_cpu_dying;
      *(_QWORD *)(StatusReg + 80) = &waltgov_tunables_save__alloc_tag;
      v8 = _kmalloc_cache_noprof(v17, 3520, 304);
      *(_QWORD *)(StatusReg + 80) = v16;
      if ( !v8 )
        goto LABEL_5;
    }
    else
    {
      v1 = &_per_cpu_offset;
      v2 = (char *)&cached_tunables;
      v8 = *(_QWORD *)((char *)&cached_tunables + *((_QWORD *)&_per_cpu_offset + v7));
      if ( v8 )
      {
LABEL_4:
        *(_BYTE *)(v8 + 216) = *(_BYTE *)(v5 + 216);
        *(_DWORD *)(v8 + 176) = *(_DWORD *)(v5 + 176);
        *(_DWORD *)(v8 + 188) = *(_DWORD *)(v5 + 188);
        *(_DWORD *)(v8 + 180) = *(_DWORD *)(v5 + 180);
        *(_DWORD *)(v8 + 184) = *(_DWORD *)(v5 + 184);
        *(_DWORD *)(v8 + 168) = *(_DWORD *)(v5 + 168);
        *(_DWORD *)(v8 + 172) = *(_DWORD *)(v5 + 172);
        *(_DWORD *)(v8 + 220) = *(_DWORD *)(v5 + 220);
        *(_DWORD *)(v8 + 192) = *(_DWORD *)(v5 + 192);
        *(_DWORD *)(v8 + 196) = *(_DWORD *)(v5 + 196);
        *(_DWORD *)(v8 + 200) = *(_DWORD *)(v5 + 200);
        *(_DWORD *)(v8 + 204) = *(_DWORD *)(v5 + 204);
        *(_DWORD *)(v8 + 208) = *(_DWORD *)(v5 + 208);
        *(_DWORD *)(v8 + 212) = *(_DWORD *)(v5 + 212);
        *(_DWORD *)(v8 + 224) = *(_DWORD *)(v5 + 224);
        *(_DWORD *)(v8 + 228) = *(_DWORD *)(v5 + 228);
        *(_DWORD *)(v8 + 232) = *(_DWORD *)(v5 + 232);
        *(_DWORD *)(v8 + 236) = *(_DWORD *)(v5 + 236);
        *(_DWORD *)(v8 + 240) = *(_DWORD *)(v5 + 240);
        *(_DWORD *)(v8 + 244) = *(_DWORD *)(v5 + 244);
        *(_DWORD *)(v8 + 248) = *(_DWORD *)(v5 + 248);
        *(_DWORD *)(v8 + 252) = *(_DWORD *)(v5 + 252);
        *(_DWORD *)(v8 + 256) = *(_DWORD *)(v5 + 256);
        *(_DWORD *)(v8 + 260) = *(_DWORD *)(v5 + 260);
        *(_DWORD *)(v8 + 264) = *(_DWORD *)(v5 + 264);
        *(_DWORD *)(v8 + 268) = *(_DWORD *)(v5 + 268);
        *(_DWORD *)(v8 + 272) = *(_DWORD *)(v5 + 272);
        *(_DWORD *)(v8 + 276) = *(_DWORD *)(v5 + 276);
        *(_DWORD *)(v8 + 280) = *(_DWORD *)(v5 + 280);
        *(_DWORD *)(v8 + 284) = *(_DWORD *)(v5 + 284);
        *(_DWORD *)(v8 + 288) = *(_DWORD *)(v5 + 288);
        *(_DWORD *)(v8 + 292) = *(_DWORD *)(v5 + 292);
        *(_DWORD *)(v8 + 296) = *(_DWORD *)(v5 + 296);
        *(_DWORD *)(v8 + 300) = *(_DWORD *)(v5 + 300);
LABEL_5:
        kfree(v5);
        goto LABEL_6;
      }
      v8 = _kmalloc_cache_noprof(_tracepoint_android_rvh_sched_cpu_dying, 3520, 304);
      if ( !v8 )
        goto LABEL_5;
    }
    v10 = 0;
    do
    {
      v11 = (unsigned int)(-1LL << v10) & *(_DWORD *)(a1 + 8);
      if ( !(_DWORD)v11 )
        break;
      v12 = __clz(__rbit64(v11));
      v13 = v1[v12];
      v14 = v12 >= 0x1F;
      v10 = v12 + 1;
      *(_QWORD *)&v2[v13] = v8;
    }
    while ( !v14 );
    goto LABEL_4;
  }
LABEL_6:
  if ( (*(_BYTE *)(*v3 + 609LL) & 1) == 0 )
  {
    kthread_flush_worker(v3 + 41);
    kthread_stop(v3[48]);
  }
  kfree(v3);
  return cpufreq_disable_fast_switch(a1);
}
