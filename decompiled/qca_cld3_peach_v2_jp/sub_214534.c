__int64 __fastcall sub_214534(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x23
  __int64 v8; // x29

  *(_QWORD *)(v8 - 360) = a7;
  *(_QWORD *)(v8 - 352) = v7;
  return wmi_set_peer_param_send(a1, a2, a3);
}
