__int64 __fastcall cam_sensor_query_cap(__int64 result, _DWORD *a2)
{
  int v2; // w8

  a2[3] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 28LL);
  a2[2] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 36LL);
  v2 = *(_DWORD *)(*(_QWORD *)(result + 3656) + 32LL);
  a2[1] = 0;
  a2[4] = v2;
  a2[5] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 44LL);
  a2[9] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 60LL);
  a2[6] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 48LL);
  a2[8] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 52LL);
  a2[7] = *(_DWORD *)(*(_QWORD *)(result + 3656) + 64LL);
  *a2 = *(_DWORD *)(result + 52);
  return result;
}
