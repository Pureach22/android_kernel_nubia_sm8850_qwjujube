unsigned __int64 __fastcall arm_lpae_install_table(
        __int64 a1,
        unsigned __int64 *a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 *a7)
{
  __int64 v14; // x0
  void (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x0
  __int64 v17; // x8
  unsigned __int64 v18; // x14
  __int64 v19; // x11
  __int64 v20; // x8
  __int64 v21; // x11
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x22
  __int64 v24; // x8
  __int64 v25; // x11
  unsigned __int64 v26; // x21
  __int64 v27; // x1
  unsigned __int64 result; // x0

  _X19 = a2;
  raw_spin_unlock_irqrestore(a6 + 248, *a7);
  v14 = *(_QWORD *)(a6 + 8);
  v15 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a6 + 232) + 16LL);
  if ( *((_DWORD *)v15 - 1) != 251140989 )
    __break(0x8228u);
  v15(v14);
  v16 = raw_spin_lock_irqsave(a6 + 248);
  v17 = a1 << 8 >> 8;
  *a7 = v16;
  v18 = (unsigned __int64)(v17 + 0x8000000000LL) >> 38;
  v19 = memstart_addr + v17 + 0x8000000000LL;
  v20 = v17 - kimage_voffset;
  if ( !v18 )
    v20 = v19;
  v21 = 3;
  v22 = v20 & 0xFFFFFFFFFFFFF000LL;
  if ( (*(_QWORD *)(a4 + 8) & 1LL) != 0 )
    v21 = 0x8000000000000003LL;
  __dmb(2u);
  v23 = v22 & 0xFF8FFFFFFFFFFFFFLL | v21 | (4 * (a5 & 0x3FF)) | ((unsigned __int64)((a5 >> 10) & 7) << 52);
  __asm { PRFM            #0x11, [X19] }
  do
    result = __ldxr(_X19);
  while ( result == a3 && __stxr(v23, _X19) );
  if ( (*(_BYTE *)(a4 + 32) & 1) == 0 && (result & 0x80000000000000LL) == 0 )
  {
    v24 = *(_QWORD *)(a4 + 48);
    if ( (*(_BYTE *)(v24 + 844) & 0x40) == 0 )
    {
      v25 = (__int64)((_QWORD)_X19 << 8) >> 8;
      v26 = result;
      if ( (unsigned __int64)(v25 + 0x8000000000LL) >> 38 )
        v27 = v25 - kimage_voffset;
      else
        v27 = memstart_addr + v25 + 0x8000000000LL;
      _dma_sync_single_for_device(v24, v27, 8, 1);
      result = v26;
    }
    if ( result == a3 )
      *_X19 = v23 | 0x80000000000000LL;
  }
  return result;
}
