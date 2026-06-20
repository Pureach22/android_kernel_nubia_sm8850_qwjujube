__int64 __fastcall sub_13CEC(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x11
  __int64 v3; // x16

  *v2 = v3;
  v2[1] = a2;
  return mhi_get_channel_doorbell_offset(a1, a2);
}
