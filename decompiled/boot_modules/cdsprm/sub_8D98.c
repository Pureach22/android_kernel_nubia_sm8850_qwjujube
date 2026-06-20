__int64 __fastcall sub_8D98(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int128 v7; // q19
  __int128 v8; // q22

  *(_OWORD *)(a7 - 656) = v7;
  *(_OWORD *)(a7 - 640) = v8;
  return hvx_set_cur_state();
}
