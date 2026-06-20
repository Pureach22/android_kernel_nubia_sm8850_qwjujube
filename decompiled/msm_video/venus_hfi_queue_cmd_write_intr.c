__int64 __fastcall venus_hfi_queue_cmd_write_intr(__int64 a1, unsigned int *a2, char a3)
{
  __int64 result; // x0
  __int64 v6; // x8
  void (__fastcall *v7)(_QWORD); // x8
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  result = _iface_cmdq_write_relaxed(a1, a2, v8);
  if ( !(_DWORD)result && (a3 & 1) != 0 )
  {
    if ( a1 )
    {
      if ( (v8[0] & 1) != 0 )
      {
        v6 = *(_QWORD *)(a1 + 6544);
        if ( v6 )
        {
          v7 = *(void (__fastcall **)(_QWORD))(v6 + 8);
          if ( v7 )
          {
            if ( *((_DWORD *)v7 - 1) != -1850880742 )
              __break(0x8228u);
            v7(a1);
            result = 0;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
