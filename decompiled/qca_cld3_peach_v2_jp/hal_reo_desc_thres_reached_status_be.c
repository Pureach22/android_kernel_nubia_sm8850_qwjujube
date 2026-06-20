__int64 __fastcall hal_reo_desc_thres_reached_status_be(_DWORD *a1, _DWORD *a2, __int64 a3)
{
  _DWORD *v5; // x8
  __int64 result; // x0

  v5 = *(_DWORD **)(*(_QWORD *)(a3 + 74392) + 432LL);
  if ( *(v5 - 1) != -386617991 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_DWORD *, __int64, _DWORD *))v5)(a1, 307, a2);
  a2[3] = a1[4] & 3;
  a2[4] = a1[5] & 0xFFFFFF;
  a2[5] = a1[6] & 0xFFFFFF;
  a2[6] = a1[7] & 0xFFFFFF;
  a2[7] = a1[8] & 0x3FFFFFF;
  return result;
}
