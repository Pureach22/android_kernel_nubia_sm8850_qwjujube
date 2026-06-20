__int64 __fastcall fastrpc_create_persistent_headers(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x24
  int v9; // w10
  __int64 v10; // x23
  int v11; // w0
  __int64 v12; // x21
  __int64 v13; // x9
  int v14; // w10
  __int64 v15; // x11
  __int64 v16; // x9
  __int64 v17; // x10
  int v18; // w8
  int v19; // w20
  __int64 v20; // [xsp+0h] [xbp-120h] BYREF
  _QWORD v21[2]; // [xsp+8h] [xbp-118h] BYREF
  __int64 v22; // [xsp+18h] [xbp-108h] BYREF
  int v23; // [xsp+20h] [xbp-100h] BYREF
  __int64 v24; // [xsp+24h] [xbp-FCh]
  int v25; // [xsp+2Ch] [xbp-F4h]
  __int64 v26; // [xsp+30h] [xbp-F0h]
  __int64 v27; // [xsp+38h] [xbp-E8h]
  _QWORD v28[15]; // [xsp+40h] [xbp-E0h] BYREF
  _QWORD v29[3]; // [xsp+B8h] [xbp-68h] BYREF
  _QWORD *v30; // [xsp+D0h] [xbp-50h]
  __int64 v31; // [xsp+D8h] [xbp-48h]
  __int64 v32; // [xsp+E0h] [xbp-40h]
  _QWORD *v33; // [xsp+E8h] [xbp-38h]
  __int64 v34; // [xsp+F0h] [xbp-30h]
  __int64 v35; // [xsp+F8h] [xbp-28h]
  __int64 *v36; // [xsp+100h] [xbp-20h]
  __int64 v37; // [xsp+108h] [xbp-18h]
  __int64 v38; // [xsp+110h] [xbp-10h]
  __int64 v39; // [xsp+118h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a1 + 136);
  v20 = 0;
  v3 = *v2;
  result = fastrpc_smmu_buf_alloc(a1, 0x8000u, 0, (__int64)&v20);
  if ( (_DWORD)result )
    goto LABEL_6;
  v5 = v20;
  v31 = 0;
  v32 = 0;
  v29[2] = 0;
  v30 = nullptr;
  v6 = *(__int64 *)((char *)&qword_40 + v20);
  v7 = *(__int64 *)((char *)&qword_40 + v20 + 8);
  v8 = *(__int64 *)((char *)&qword_30 + v20);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = nullptr;
  v33 = nullptr;
  v34 = 0;
  v22 = 0;
  if ( !a1 )
  {
    v19 = -9;
LABEL_9:
    dev_err(v3, "Warning: failed to map len %zu, flags %d, num headers %u with err %d\n", 0x8000u, 0x4000, 8, v19);
    result = fastrpc_buf_free(v5, 0);
    goto LABEL_6;
  }
  v9 = *(_DWORD *)(a1 + 244);
  v10 = **(_QWORD **)(a1 + 136);
  v21[0] = v6;
  v21[1] = v7;
  v24 = 0xFFFFFFFFLL;
  v25 = 0x4000;
  v26 = 0;
  v27 = 16;
  v30 = v21;
  v31 = 16;
  v33 = v21;
  v34 = 0;
  v36 = &v22;
  v37 = 8;
  v23 = v9;
  memset(&v28[2], 0, 104);
  v29[0] = &v23;
  v29[1] = 32;
  v28[0] = 0xA03010000000001LL;
  v28[1] = v29;
  v11 = fastrpc_internal_invoke(a1, 1u, (int *)v28);
  if ( v11 )
  {
    v19 = v11;
    dev_err(v10, "mem mmap error, fd %d, vaddr %llx, size %zx, err 0x%x\n", -1, 0, v7, v11);
    goto LABEL_9;
  }
  *(__int64 *)((char *)&qword_90 + v5) = v22;
  result = _kmalloc_cache_noprof(of_find_property, 3520, 1792);
  v12 = result;
  if ( result )
  {
    raw_spin_lock(a1 + 320);
    *(_QWORD *)(a1 + 168) = v5;
    *(_DWORD *)(a1 + 276) = 8;
    *(_QWORD *)(a1 + 192) = v12;
    *(_QWORD *)(v12 + 16) = a1;
    *(_QWORD *)(v12 + 48) = v8;
    v13 = *(__int64 *)((char *)&qword_40 + v5);
    *(_QWORD *)(v12 + 64) = v13;
    *(_QWORD *)(v12 + 72) = 4096;
    v14 = *(int *)((char *)&dword_38 + v5);
    *(_QWORD *)(v12 + 272) = v8 + 4096;
    *(_QWORD *)(v12 + 288) = v13 + 4096;
    *(_QWORD *)(v12 + 296) = 4096;
    *(_QWORD *)(v12 + 496) = v8 + 0x2000;
    *(_QWORD *)(v12 + 512) = v13 + 0x2000;
    *(_QWORD *)(v12 + 720) = v8 + 12288;
    *(_QWORD *)(v12 + 736) = v13 + 12288;
    *(_QWORD *)(v12 + 944) = v8 + 0x4000;
    *(_QWORD *)(v12 + 960) = v13 + 0x4000;
    *(_QWORD *)(v12 + 1168) = v8 + 20480;
    v15 = v13 + 20480;
    *(_QWORD *)(v12 + 1408) = v13 + 24576;
    v16 = *(_QWORD *)(a1 + 192);
    *(_DWORD *)(v12 + 56) = v14;
    *(_DWORD *)(v12 + 280) = v14;
    *(_DWORD *)(v12 + 504) = v14;
    *(_DWORD *)(v12 + 728) = v14;
    *(_DWORD *)(v12 + 952) = v14;
    *(_QWORD *)(v12 + 1184) = v15;
    *(_DWORD *)(v12 + 1176) = v14;
    *(_DWORD *)(v12 + 1400) = v14;
    *(_BYTE *)(v12 + 152) = 0;
    *(_QWORD *)(v12 + 240) = a1;
    *(_BYTE *)(v12 + 376) = 0;
    *(_QWORD *)(v12 + 464) = a1;
    *(_QWORD *)(v12 + 520) = 4096;
    *(_BYTE *)(v12 + 600) = 0;
    *(_QWORD *)(v12 + 688) = a1;
    *(_QWORD *)(v12 + 744) = 4096;
    *(_BYTE *)(v12 + 824) = 0;
    *(_QWORD *)(v12 + 912) = a1;
    *(_QWORD *)(v12 + 968) = 4096;
    *(_BYTE *)(v12 + 1048) = 0;
    *(_QWORD *)(v12 + 1136) = a1;
    *(_QWORD *)(v12 + 1192) = 4096;
    *(_BYTE *)(v12 + 1272) = 0;
    *(_QWORD *)(v12 + 1360) = a1;
    *(_QWORD *)(v12 + 1392) = v8 + 24576;
    *(_QWORD *)(v12 + 1416) = 4096;
    *(_BYTE *)(v12 + 1496) = 0;
    *(_QWORD *)(v16 + 1584) = a1;
    *(_QWORD *)(v16 + 1616) = v8 + 28672;
    v17 = *(__int64 *)((char *)&qword_40 + v5);
    *(_QWORD *)(v16 + 1640) = 4096;
    *(_QWORD *)(v16 + 1632) = v17 + 28672;
    v18 = *(int *)((char *)&dword_38 + v5);
    *(_BYTE *)(v16 + 1720) = 0;
    *(_DWORD *)(v16 + 1624) = v18;
    result = raw_spin_unlock(a1 + 320);
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
