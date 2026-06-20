__int64 __fastcall venus_hfi_queue_cmd_write(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  result = _iface_cmdq_write_relaxed(a1, a2, v6);
  if ( !(_DWORD)result )
  {
    if ( a1 )
    {
      if ( (v6[0] & 1) != 0 )
      {
        v4 = *(_QWORD *)(a1 + 6544);
        if ( v4 )
        {
          v5 = *(void (__fastcall **)(_QWORD))(v4 + 8);
          if ( v5 )
          {
            if ( *((_DWORD *)v5 - 1) != -1850880742 )
              __break(0x8228u);
            v5(a1);
            result = 0;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
