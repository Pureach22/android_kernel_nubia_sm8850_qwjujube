__int64 __fastcall sub_D8C8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x10
  __int64 v6; // x15

  *(_QWORD *)(a5 + 176) = v6;
  *(_QWORD *)(a5 + 184) = v5;
  return mhi_init_chan_ctxt(a1, a2, a3, a4, a5 + 176);
}
