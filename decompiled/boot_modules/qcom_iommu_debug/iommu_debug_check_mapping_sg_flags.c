__int64 __fastcall iommu_debug_check_mapping_sg_flags(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        int a6)
{
  __int64 v6; // x23
  __int64 result; // x0
  __int64 v12; // [xsp+8h] [xbp-38h] BYREF
  __int64 v13; // [xsp+10h] [xbp-30h]
  __int64 v14; // [xsp+18h] [xbp-28h]
  _QWORD *v15; // [xsp+20h] [xbp-20h] BYREF
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v6 = a3;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = nullptr;
  v12 = 0;
  v13 = 0;
  _sg_page_iter_start(&v15, a2, a5, a3);
  _sg_page_iter_start(&v12, a2, a4, v6);
  while ( (_sg_page_iter_next(&v15) & 1) != 0 && (_sg_page_iter_dma_next(&v12) & 1) != 0 )
  {
    result = iommu_debug_check_mapping_flags(
               a1,
               *(_QWORD *)(v12 + 16) + (unsigned int)((_DWORD)v13 << 12),
               4096,
               (((*v15 & 0x3FFFFFFFFFFFFFCLL)
               + ((unsigned __int64)(unsigned int)v16 << 6)
               - -64LL * (memstart_addr >> 12)) << 6)
             + 0x5000000000LL,
               a6);
    if ( (_DWORD)result )
      goto LABEL_7;
  }
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
