__int64 __fastcall hif_record_latest_evt(__int64 result, unsigned __int8 a2, int a3, __int64 a4, int a5, int a6)
{
  _QWORD *v6; // x8
  _QWORD *v7; // x8
  _QWORD *v8; // x8
  unsigned __int64 StatusReg; // x10
  int v10; // w9
  __int64 v11; // x11
  int v12; // [xsp+4h] [xbp-1Ch]
  _QWORD *v13; // [xsp+8h] [xbp-18h]

  if ( (unsigned int)(a3 - 4) < 0xFFFFFFFE )
    return result;
  v6 = (_QWORD *)(result + 112LL * (unsigned int)(a3 - 2) + 960);
  if ( a2 <= 0x11u )
  {
    if ( a2 != 5 )
    {
      if ( a2 == 16 )
      {
        v8 = &v6[7 * (*v6 > *(_QWORD *)(result + 112LL * (unsigned int)(a3 - 2) + 1016))];
        StatusReg = _ReadStatusReg(SP_EL0);
        *v8 = a4;
        ++*(_DWORD *)(StatusReg + 16);
        v10 = *(_DWORD *)(StatusReg + 40);
        v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v11;
        if ( v11 && *(_QWORD *)(StatusReg + 16) )
        {
          *((_DWORD *)v8 + 10) = v10;
        }
        else
        {
          v13 = v8;
          v12 = v10;
          result = preempt_schedule();
          *((_DWORD *)v13 + 10) = v12;
        }
      }
      else if ( a2 == 17 )
      {
        v6[7
         * (*(_QWORD *)(result + 112LL * (unsigned int)(a3 - 2) + 968) > *(_QWORD *)(result
                                                                                   + 112LL * (unsigned int)(a3 - 2)
                                                                                   + 1024))
         + 1] = a4;
      }
      return result;
    }
LABEL_11:
    v7 = &v6[7
           * (*(_QWORD *)(result + 112LL * (unsigned int)(a3 - 2) + 992) > *(_QWORD *)(result
                                                                                     + 112LL * (unsigned int)(a3 - 2)
                                                                                     + 1048))];
    v7[4] = a4;
    *((_DWORD *)v7 + 11) = a5;
    *((_DWORD *)v7 + 12) = a6;
    return result;
  }
  switch ( a2 )
  {
    case 0x12u:
      v6[7
       * (*(_QWORD *)(result + 112LL * (unsigned int)(a3 - 2) + 976) > *(_QWORD *)(result
                                                                                 + 112LL * (unsigned int)(a3 - 2)
                                                                                 + 1032))
       + 2] = a4;
      return result;
    case 0x14u:
      v6[7
       * (*(_QWORD *)(result + 112LL * (unsigned int)(a3 - 2) + 984) > *(_QWORD *)(result
                                                                                 + 112LL * (unsigned int)(a3 - 2)
                                                                                 + 1040))
       + 3] = a4;
      return result;
    case 0x26u:
      goto LABEL_11;
  }
  return result;
}
