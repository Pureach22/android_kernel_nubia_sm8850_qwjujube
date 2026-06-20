__int64 __fastcall dot11f_pack_tlv_p2_p_device_info(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, int *a5)
{
  int v5; // w24
  __int64 result; // x0
  void *v7; // x20
  unsigned int v12; // w21
  int v13; // w8
  unsigned int v14; // w19
  int v15; // [xsp+0h] [xbp-10h] BYREF
  __int16 v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a5;
  v15 = 0;
  if ( a4 >= 0x13 )
  {
    if ( *(_BYTE *)a2 )
    {
      v7 = (void *)(a3 + 1);
      *(_BYTE *)a3 = 13;
      v12 = a4 - 3;
      *a5 += 3;
      qdf_mem_copy((void *)(a3 + 3), (const void *)(a2 + 1), 6u);
      *a5 += 6;
      *(_WORD *)(a3 + 9) = bswap32(*(unsigned __int16 *)(a2 + 8)) >> 16;
      *a5 += 2;
      qdf_mem_copy((void *)(a3 + 11), (const void *)(a2 + 10), 8u);
      *a5 += 8;
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, int *, void *, int *))pack_tlv_core)(
                 a1,
                 a2,
                 a3 + 19,
                 v12,
                 a5,
                 &TLVS_P2PDeviceInfo,
                 &v15);
      if ( v7 )
      {
        v13 = *a5;
        v14 = result;
        v16 = v13 - v5 - 3;
        qdf_mem_copy(v7, &v16, 2u);
        result = v14;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 268435461;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
