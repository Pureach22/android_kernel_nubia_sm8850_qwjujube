__int64 __fastcall enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x9
  __int64 v7; // x22
  int v8; // w0
  __int64 v9; // x21
  int v10; // w0
  int v11; // w21
  unsigned int v12; // w8
  unsigned int v19; // w10
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 96);
  v21[0] = 0;
  v7 = *(_QWORD *)(v6 + 152);
  v8 = kstrtoull(a3, 0, v21);
  if ( !v8 )
  {
    if ( v21[0] )
    {
      v9 = *(_QWORD *)(a1 + 96);
      v8 = _pm_runtime_resume(v9, 4);
      if ( v8 < 0 )
      {
        v12 = *(_DWORD *)(v9 + 480);
        do
        {
          if ( !v12 )
            break;
          _X12 = (unsigned int *)(v9 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v19 = __ldxr(_X12);
            if ( v19 != v12 )
              break;
            if ( !__stlxr(v12 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v19 == v12;
          v12 = v19;
        }
        while ( !_ZF );
        goto LABEL_2;
      }
      v10 = cti_enable(*(_QWORD *)(v7 + 8));
      if ( !v10 )
        goto LABEL_19;
      v11 = v10;
      _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
    }
    else
    {
      v11 = cti_disable(*(_QWORD *)(v7 + 8));
      if ( !v11 )
      {
        _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
        goto LABEL_19;
      }
    }
    a4 = v11;
    goto LABEL_19;
  }
LABEL_2:
  a4 = v8;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return a4;
}
