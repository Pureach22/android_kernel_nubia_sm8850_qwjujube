__int64 __fastcall cam_ife_mgr_eof_irq_enable(__int64 result, char a2)
{
  __int64 v2; // x21
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x27
  __int64 v5; // x28
  const char *v6; // x19
  _DWORD *v7; // x20
  _DWORD *v8; // x9
  __int64 v9; // x0
  const char *v10; // x6
  __int64 v11; // [xsp+8h] [xbp-18h]
  _BYTE v12[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(result + 8716);
  v12[0] = a2;
  if ( (_DWORD)v3 )
  {
    v4 = 0;
    v5 = *(_QWORD *)(result + 72) + 96LL;
    if ( (a2 & 1) != 0 )
      v6 = "enable";
    else
      v6 = "disable";
    v7 = (_DWORD *)(result + 8592);
    while ( v4 != 11 )
    {
      if ( !*v7 && !*(v7 - 1) )
      {
        v3 = debug_mdl;
        v2 = (unsigned int)*(v7 - 2);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v11 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_eof_irq_enable",
            15830,
            "%s EOF IRQ for CSID[%u]",
            v6,
            v2);
          result = v11;
          if ( (unsigned int)v2 > 7 )
            break;
        }
        else if ( (unsigned int)v2 > 7 )
        {
          break;
        }
        v3 = *(_QWORD *)(v5 + 8 * v2);
        if ( v3 )
          goto LABEL_17;
        v3 = *(unsigned int *)(result + 8716);
      }
      ++v4;
      v7 += 3;
      if ( v4 >= v3 )
        goto LABEL_22;
    }
    __break(0x5512u);
LABEL_17:
    v8 = *(_DWORD **)(v3 + 88);
    v9 = *(_QWORD *)(v3 + 112);
    if ( *(v8 - 1) != -1055839300 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64))v8)(v9, 48, v12, 1);
    if ( (_DWORD)result && (debug_mdl & 8) != 0 && !debug_priority )
    {
      if ( v12[0] )
        v10 = "enable";
      else
        v10 = "disable";
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, _DWORD))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_mgr_eof_irq_enable",
                 15839,
                 "Failed to %s CSID[%u] EOF IRQ rc: %d",
                 v10,
                 (unsigned int)v2,
                 result);
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
