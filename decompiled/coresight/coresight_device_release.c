__int64 __fastcall coresight_device_release(__int64 a1)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x9
  void (__fastcall *v3)(_QWORD); // x9
  __int64 v4; // x19
  __int64 v5; // x0

  v1 = *(_QWORD *)(a1 + 752);
  if ( v1 )
  {
    if ( v1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v2 = *(_QWORD *)(v1 + 8);
      if ( v2 )
      {
        v3 = *(void (__fastcall **)(_QWORD))(v2 + 8);
        if ( v3 )
        {
          v4 = a1;
          v5 = *(_QWORD *)(a1 + 752);
          if ( *((_DWORD *)v3 - 1) != -643302289 )
            __break(0x8229u);
          v3(v5);
          a1 = v4;
        }
      }
    }
  }
  return kfree(a1 - 56);
}
