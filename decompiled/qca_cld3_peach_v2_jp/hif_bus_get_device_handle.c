__int64 __fastcall hif_bus_get_device_handle(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 (__fastcall *v4)(_QWORD); // x9

  result = 29;
  if ( a1 && a2 )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(a1 + 472);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 898496867 )
        __break(0x8229u);
      return v4(a1);
    }
    else
    {
      return 16;
    }
  }
  return result;
}
