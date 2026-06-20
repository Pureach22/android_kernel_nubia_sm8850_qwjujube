__int64 __fastcall usb_put_redriver(__int64 result)
{
  __int64 v1; // x19
  __int64 (__fastcall *v2)(_QWORD); // x8

  if ( result )
  {
    v1 = result;
    raw_spin_lock(&usb_rediver_lock);
    *(_BYTE *)(v1 + 80) = 0;
    result = raw_spin_unlock(&usb_rediver_lock);
    v2 = *(__int64 (__fastcall **)(_QWORD))(v1 + 72);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 140858188 )
        __break(0x8228u);
      return v2(v1);
    }
  }
  return result;
}
