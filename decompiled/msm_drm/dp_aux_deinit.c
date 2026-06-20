__int64 __fastcall dp_aux_deinit(__int64 result)
{
  __int64 v1; // x19
  _DWORD *v2; // x9
  __int64 v3; // x0

  if ( result )
  {
    if ( *(_BYTE *)(result + 1807) == 1 )
    {
      *(_DWORD *)(result + 1832) = 1;
      v1 = result;
      v2 = *(_DWORD **)(*(_QWORD *)(result + 120) + 48LL);
      v3 = *(_QWORD *)(result + 120);
      if ( *(v2 - 1) != 497885965 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD))v2)(v3, 0);
      *(_BYTE *)(v1 + 1807) = 0;
    }
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    return printk(&unk_275B6D, "dp_aux_deinit");
  }
  return result;
}
