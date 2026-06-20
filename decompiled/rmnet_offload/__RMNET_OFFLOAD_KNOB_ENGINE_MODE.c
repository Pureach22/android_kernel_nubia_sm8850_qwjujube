__int64 __fastcall _RMNET_OFFLOAD_KNOB_ENGINE_MODE(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 (__fastcall *v8)(__int64, __int64); // x9
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  result = kstrtoull(a1, 0, v9);
  if ( (result & 0x80000000) == 0 )
  {
    result = 4294967262LL;
    if ( v9[0] >= (unsigned __int64)qword_A8 && v9[0] <= (unsigned __int64)qword_B0 )
    {
      rmnet_offload_lock(4294967262LL);
      v4 = *(__int64 **)(a2 + 32);
      v5 = v9[0];
      v6 = *v4;
      if ( v9[0] == *v4 )
      {
        v7 = 0;
      }
      else
      {
        v8 = (__int64 (__fastcall *)(__int64, __int64))off_B8;
        if ( off_B8 )
        {
          if ( *((_DWORD *)off_B8 - 1) != 75230599 )
            __break(0x8229u);
          v6 = v8(v6, v5);
          if ( (v6 & 0x80000000) != 0 )
          {
            v7 = v6;
            goto LABEL_13;
          }
          v5 = v9[0];
          v4 = *(__int64 **)(a2 + 32);
        }
        v7 = 0;
        *v4 = v5;
      }
LABEL_13:
      rmnet_offload_unlock(v6);
      result = v7;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
