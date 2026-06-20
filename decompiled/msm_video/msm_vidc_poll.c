__int64 __fastcall msm_vidc_poll(_QWORD *a1, __int64 a2, _DWORD **a3)
{
  _DWORD *v4; // x8
  __int64 v6; // x21
  __int64 v7; // x9
  _DWORD *v8; // x8
  __int64 v9; // x9
  __int64 *v10; // x22
  __int64 v11; // x1
  __int64 v12; // x9
  int v13; // w0
  __int64 v14; // x23
  int v15; // w20
  __int64 v16; // x0
  __int64 v17; // x8
  int v18; // w21
  __int64 v19; // x24
  __int64 v20; // x0
  __int64 v21; // x8
  int v22; // w23
  __int64 v23; // x24
  __int64 v24; // x0
  __int64 v25; // x8
  int v26; // w22
  __int64 v27; // x19
  __int64 v28; // x0
  __int64 v29; // x8
  int v30; // w24

  if ( a3 && (v4 = *a3) != nullptr )
  {
    v6 = a2;
    if ( *(v4 - 1) != -442429149 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v4)(a2, a1 + 211);
    __dmb(0xBu);
    v7 = a1[232];
    v8 = *a3;
    if ( v7 != -296 && v8 )
    {
      if ( *(v8 - 1) != -442429149 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _DWORD **))v8)(v6, v7 + 296, a3);
      __dmb(0xBu);
      v8 = *a3;
    }
    v9 = a1[233];
    v10 = a1 + 230;
    if ( v9 != -296 && v8 )
    {
      if ( *(v8 - 1) != -442429149 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _DWORD **))v8)(v6, v9 + 296, a3);
      __dmb(0xBu);
      v8 = *a3;
    }
    v11 = *v10 + 296;
    if ( *v10 != -296 && v8 )
    {
      if ( *(v8 - 1) != -442429149 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _DWORD **))v8)(v6, v11, a3);
      __dmb(0xBu);
      v8 = *a3;
    }
    v12 = a1[231];
    a2 = v12 + 296;
    if ( v12 != -296 && v8 )
    {
      if ( *(v8 - 1) != -442429149 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _DWORD **))v8)(v6, a2, a3);
      __dmb(0xBu);
    }
  }
  else
  {
    v10 = a1 + 230;
  }
  v13 = v4l2_event_pending(a1 + 206, a2);
  v14 = a1[232];
  v15 = v13;
  v16 = raw_spin_lock_irqsave(v14 + 288);
  v17 = *(_QWORD *)(v14 + 272);
  v18 = 0;
  if ( v17 != v14 + 272 && v17 != 560 )
  {
    if ( (unsigned int)(*(_DWORD *)(v17 - 472) - 5) >= 2 )
      v18 = 0;
    else
      v18 = 260;
  }
  raw_spin_unlock_irqrestore(v14 + 288, v16);
  v19 = a1[233];
  v20 = raw_spin_lock_irqsave(v19 + 288);
  v21 = *(_QWORD *)(v19 + 272);
  v22 = 0;
  if ( v21 != v19 + 272 && v21 != 560 )
  {
    if ( (unsigned int)(*(_DWORD *)(v21 - 472) - 5) >= 2 )
      v22 = 0;
    else
      v22 = 65;
  }
  raw_spin_unlock_irqrestore(v19 + 288, v20);
  v23 = *v10;
  v24 = raw_spin_lock_irqsave(*v10 + 288);
  v25 = *(_QWORD *)(v23 + 272);
  v26 = 0;
  if ( v25 != v23 + 272 && v25 != 560 )
  {
    if ( (unsigned int)(*(_DWORD *)(v25 - 472) - 5) >= 2 )
      v26 = 0;
    else
      v26 = 260;
  }
  raw_spin_unlock_irqrestore(v23 + 288, v24);
  v27 = a1[231];
  v28 = raw_spin_lock_irqsave(v27 + 288);
  v29 = *(_QWORD *)(v27 + 272);
  v30 = 0;
  if ( v29 != v27 + 272 && v29 != 560 )
  {
    if ( (unsigned int)(*(_DWORD *)(v29 - 472) - 5) >= 2 )
      v30 = 0;
    else
      v30 = 65;
  }
  raw_spin_unlock_irqrestore(v27 + 288, v28);
  return v18 | (2 * (v15 != 0)) | v22 | v26 | (unsigned int)v30;
}
