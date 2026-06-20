__int64 memlat_hrtimer_handler()
{
  __int64 v0; // x8
  __int64 v1; // x0
  char v2; // w8
  __int64 v3; // x10
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x20
  char v11; // w8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x9
  _DWORD *v19; // x10
  _DWORD *v20; // x10
  _DWORD *v21; // x10
  _DWORD *v22; // x10
  _DWORD *v23; // x10
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x8
  int v26; // w10
  int v27; // w8
  __int64 v28; // x28
  __int64 v29; // x22
  __int64 v30; // x19
  _QWORD *v31; // x27
  __int64 v32; // x9
  __int64 v33; // x8
  int v34; // w7
  __int64 v35; // x8
  char v36; // w8
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x20
  unsigned __int64 StatusReg; // [xsp+28h] [xbp-18h]
  __int64 v41; // [xsp+30h] [xbp-10h]
  __int64 v42; // [xsp+38h] [xbp-8h]

  v0 = memlat_data;
  if ( *(_BYTE *)(memlat_data + 306) == 1 )
  {
    v1 = ktime_get();
    v2 = 0;
    v3 = *(_QWORD *)(memlat_data + 232);
    *(_QWORD *)(memlat_data + 232) = v1;
    StatusReg = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v41 = v1 - v3;
    v42 = v1;
    do
    {
      v9 = (unsigned int)(-1LL << v2) & _cpu_possible_mask;
      if ( !(_DWORD)v9 )
        break;
      v10 = __clz(__rbit64(v9));
      raw_spin_lock(*(_QWORD *)((char *)&sampling_stats + _per_cpu_offset[v10]) + 584LL);
      v2 = v10 + 1;
    }
    while ( v10 < 0x1F );
    v11 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v12 = (unsigned int)(-1LL << v11) & _cpu_possible_mask;
      _ZF = (_DWORD)v12 == 0;
      v13 = __clz(__rbit64(v12));
      if ( _ZF )
        v14 = 32;
      else
        v14 = v13;
      if ( (unsigned int)v14 > 0x1F )
        break;
      v15 = *(_QWORD *)((char *)&sampling_stats + _per_cpu_offset[v14]);
      if ( *(_BYTE *)(v15 + 560) == 1 )
      {
        v16 = v41;
        v17 = v42;
      }
      else
      {
        v17 = *(_QWORD *)(v15 + 568);
        v16 = v17 - *(_QWORD *)(v15 + 576);
      }
      *(_QWORD *)(v15 + 576) = v17;
      v18 = memlat_data;
      if ( *(_DWORD *)(memlat_data + 104) )
        *(_QWORD *)(v15 + 304) = *(_QWORD *)(v15 + 152) - *(_QWORD *)v15;
      if ( *(_DWORD *)(v18 + 108) )
      {
        *(_QWORD *)(v15 + 312) = *(_QWORD *)(v15 + 160) - *(_QWORD *)(v15 + 8);
        v18 = memlat_data;
      }
      if ( *(_DWORD *)(v18 + 112) )
      {
        *(_QWORD *)(v15 + 320) = *(_QWORD *)(v15 + 168) - *(_QWORD *)(v15 + 16);
        v18 = memlat_data;
      }
      if ( *(_DWORD *)(v18 + 116) )
      {
        *(_QWORD *)(v15 + 328) = *(_QWORD *)(v15 + 176) - *(_QWORD *)(v15 + 24);
        v18 = memlat_data;
      }
      v19 = *(_DWORD **)(v18 + 248);
      if ( v19 )
      {
        if ( v19[18] )
          *(_QWORD *)(v15 + 336) = *(_QWORD *)(v15 + 184) - *(_QWORD *)(v15 + 32);
        if ( v19[19] )
          *(_QWORD *)(v15 + 344) = *(_QWORD *)(v15 + 192) - *(_QWORD *)(v15 + 40);
        if ( v19[20] )
          *(_QWORD *)(v15 + 352) = *(_QWORD *)(v15 + 200) - *(_QWORD *)(v15 + 48);
        v18 = memlat_data;
      }
      v20 = *(_DWORD **)(v18 + 256);
      if ( v20 )
      {
        if ( v20[18] )
          *(_QWORD *)(v15 + 360) = *(_QWORD *)(v15 + 208) - *(_QWORD *)(v15 + 56);
        if ( v20[19] )
          *(_QWORD *)(v15 + 368) = *(_QWORD *)(v15 + 216) - *(_QWORD *)(v15 + 64);
        if ( v20[20] )
          *(_QWORD *)(v15 + 376) = *(_QWORD *)(v15 + 224) - *(_QWORD *)(v15 + 72);
        v18 = memlat_data;
      }
      v21 = *(_DWORD **)(v18 + 264);
      if ( v21 )
      {
        if ( v21[18] )
          *(_QWORD *)(v15 + 384) = *(_QWORD *)(v15 + 232) - *(_QWORD *)(v15 + 80);
        if ( v21[19] )
          *(_QWORD *)(v15 + 392) = *(_QWORD *)(v15 + 240) - *(_QWORD *)(v15 + 88);
        if ( v21[20] )
          *(_QWORD *)(v15 + 400) = *(_QWORD *)(v15 + 248) - *(_QWORD *)(v15 + 96);
        v18 = memlat_data;
      }
      v22 = *(_DWORD **)(v18 + 272);
      if ( v22 )
      {
        if ( v22[18] )
          *(_QWORD *)(v15 + 408) = *(_QWORD *)(v15 + 256) - *(_QWORD *)(v15 + 104);
        if ( v22[19] )
          *(_QWORD *)(v15 + 416) = *(_QWORD *)(v15 + 264) - *(_QWORD *)(v15 + 112);
        if ( v22[20] )
          *(_QWORD *)(v15 + 424) = *(_QWORD *)(v15 + 272) - *(_QWORD *)(v15 + 120);
        v18 = memlat_data;
      }
      v23 = *(_DWORD **)(v18 + 280);
      if ( v23 )
      {
        if ( v23[18] )
          *(_QWORD *)(v15 + 432) = *(_QWORD *)(v15 + 280) - *(_QWORD *)(v15 + 128);
        if ( v23[19] )
          *(_QWORD *)(v15 + 440) = *(_QWORD *)(v15 + 288) - *(_QWORD *)(v15 + 136);
        if ( v23[20] )
          *(_QWORD *)(v15 + 448) = *(_QWORD *)(v15 + 296) - *(_QWORD *)(v15 + 144);
        v18 = memlat_data;
      }
      v24 = v16 / 1000;
      v25 = *(_QWORD *)(v15 + 312);
      *(_DWORD *)(v15 + 588) = v25 / v24;
      v26 = *(_DWORD *)(v18 + 112)
          ? 0x64 % v25 * *(_QWORD *)(v15 + 320) / v25 + 0x64 / v25 * *(_QWORD *)(v15 + 320)
          : 100;
      *(_DWORD *)(v15 + 592) = v26;
      v27 = *(_DWORD *)(v18 + 116)
          ? 0x64 % v25 * *(_QWORD *)(v15 + 328) / v25 + 0x64 / v25 * *(_QWORD *)(v15 + 328)
          : 100;
      v28 = v15 + 336;
      v29 = 0;
      v30 = 248;
      v31 = (_QWORD *)(v15 + 336);
      *(_DWORD *)(v15 + 596) = v27;
      do
      {
        v32 = *(_QWORD *)(memlat_data + v30);
        if ( v32 )
        {
          v33 = *(_QWORD *)(v15 + 304);
          *(_DWORD *)(v28 + v29 + 264) = v33;
          if ( *v31 )
            *(_DWORD *)(v28 + v29 + 264) = (unsigned __int64)(unsigned int)v33 / *v31;
          if ( *(_DWORD *)(v32 + 76) && *(_DWORD *)(v32 + 80) )
            v34 = 0x64uLL % v31[2] * v31[1] / v31[2] + v31[1] * (0x64uLL / v31[2]);
          else
            v34 = 0;
          *(_DWORD *)(v28 + v29 + 284) = v34;
        }
        else
        {
          v35 = v28 + v29;
          *(_DWORD *)(v35 + 264) = 0;
          *(_DWORD *)(v35 + 284) = 0;
        }
        v29 += 4;
        v30 += 8;
        v31 += 3;
      }
      while ( v29 != 20 );
      memcpy((void *)v15, (const void *)(v15 + 152), 0x98u);
      v11 = v14 + 1;
    }
    while ( v14 < 0x1F );
    v36 = 0;
    do
    {
      v37 = (unsigned int)(-1LL << v36) & _cpu_possible_mask;
      if ( !(_DWORD)v37 )
        break;
      v38 = __clz(__rbit64(v37));
      raw_spin_unlock(*(_QWORD *)((char *)&sampling_stats + _per_cpu_offset[v38]) + 584LL);
      v36 = v38 + 1;
    }
    while ( v38 < 0x1F );
    _WriteStatusReg(DAIF, StatusReg);
    v0 = memlat_data;
  }
  queue_work_on(32, *(_QWORD *)(v0 + 152), v0 + 120);
  return 0;
}
