__int64 __fastcall vdev_mgr_multiple_restart_send(
        __int64 a1,
        const void *a2,
        int a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6)
{
  int v9; // w8
  int v10; // w8
  int v11; // w9
  __int64 result; // x0
  _DWORD v13[4]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v14[5]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v15; // [xsp+40h] [xbp-20h]
  __int64 v16; // [xsp+48h] [xbp-18h]
  __int64 v17; // [xsp+50h] [xbp-10h]
  __int64 v18; // [xsp+58h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 40);
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v13[0] = v9;
  v13[1] = 4660;
  v13[2] = a3;
  v13[3] = 67000;
  memset(&v14[1], 0, 32);
  v14[0] = a5;
  qdf_mem_copy((char *)v14 + 4, a2, 0x20u);
  v10 = *(_DWORD *)(a1 + 12);
  v11 = *(unsigned __int8 *)(a1 + 42);
  v15 = a4;
  v16 = a6;
  LODWORD(v17) = v11;
  BYTE4(v17) = (v10 & 0x4000000) != 0;
  result = tgt_vdev_mgr_multiple_vdev_restart_send(a1, v13);
  _ReadStatusReg(SP_EL0);
  return result;
}
