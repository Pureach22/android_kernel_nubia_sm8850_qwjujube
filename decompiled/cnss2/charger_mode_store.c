__int64 __fastcall charger_mode_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x7
  __int64 v7; // x6
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  char v13; // [xsp+0h] [xbp-10h]
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v14 = 0;
  if ( sscanf(s, "%du", &v14) == 1 )
  {
    v7 = v14;
    *(_BYTE *)(v5 + 7576) = v14;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v10 = *(_DWORD *)(StatusReg + 16);
      v11 = (const char *)(StatusReg + 2320);
      if ( (v10 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v11;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "charger_mode_store",
      7u,
      7u,
      "Received Charger Mode: %d\n",
      v7,
      v6,
      v13);
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
