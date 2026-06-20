__int64 __fastcall rate_control_deinitialize(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x0
  void (__fastcall *v3)(_QWORD); // x8

  v1 = *(_QWORD **)(result + 2536);
  if ( v1 )
  {
    *(_QWORD *)(result + 2536) = 0;
    v2 = v1[1];
    v3 = *(void (__fastcall **)(_QWORD))(*v1 + 32LL);
    if ( *((_DWORD *)v3 - 1) != 251140989 )
      __break(0x8228u);
    v3(v2);
    return kfree(v1);
  }
  return result;
}
