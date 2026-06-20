__int64 __fastcall wcd_cls_h_fsm(__int64 result, _BYTE *a2, char a3, unsigned int a4, int a5)
{
  int v5; // w9
  unsigned int v6; // w8
  unsigned int v7; // w10
  _DWORD *v8; // x8
  __int64 v9; // x8
  unsigned int v10; // w20
  _DWORD *v11; // x8
  __int64 v14; // x19
  __int64 v15; // x19
  __int64 v16; // x19
  __int64 v17; // x0
  _QWORD v18[17]; // [xsp+8h] [xbp-88h] BYREF

  v18[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 128);
  if ( a3 != 2 )
  {
    if ( a3 != 1 )
      goto LABEL_29;
    v5 = (unsigned __int8)*a2;
    v6 = v5 | a4;
    v7 = (unsigned __int8)(v5 | a4);
    if ( v7 >= 0xB && v7 != 12 && v7 != 14 )
    {
      v14 = *(_QWORD *)(result + 24);
      ((void (__fastcall *)(_QWORD, _QWORD *))state_to_str)(v6, v18);
      result = dev_err(v14, "%s: Class-H not a valid new state: %s\n", "wcd_cls_h_fsm", v18);
      goto LABEL_29;
    }
    if ( v5 != (unsigned __int8)v6 )
    {
      *a2 = v6;
      if ( (unsigned __int8)a4 <= 8u && ((1 << a4) & 0x116) != 0 )
        *(_DWORD *)&a2[4 * __clz(__rbit32(a4)) + 16] = a5;
      if ( (unsigned __int8)(v5 | a4) > 0x1Fu )
      {
        __break(1u);
        JUMPOUT(0x6CDC);
      }
      v8 = (_DWORD *)clsh_state_fp[(unsigned __int8)(v5 | a4)];
      if ( *(v8 - 1) != -12605800 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _BYTE *, _QWORD, __int64))v8)(result, a2, a4, 1);
      goto LABEL_29;
    }
    v16 = *(_QWORD *)(result + 24);
    v17 = (unsigned __int8)*a2;
LABEL_28:
    ((void (__fastcall *)(__int64, _QWORD *))state_to_str)(v17, v18);
    result = dev_err(v16, "%s: Class-H already in requested state: %s\n", "wcd_cls_h_fsm", v18);
    goto LABEL_29;
  }
  v9 = (unsigned __int8)*a2;
  v10 = v9 & ~a4;
  if ( v10 > 0x1F )
    goto LABEL_29;
  if ( (unsigned int)v9 >= 0xB && (_DWORD)v9 != 12 && (_DWORD)v9 != 14 )
  {
    v15 = *(_QWORD *)(result + 24);
    ((void (__fastcall *)(_QWORD, _QWORD *))state_to_str)((unsigned __int8)*a2, v18);
    result = dev_err(v15, "%s:Invalid old state:%s\n", "wcd_cls_h_fsm", v18);
    goto LABEL_29;
  }
  if ( v10 == (_DWORD)v9 )
  {
    v16 = *(_QWORD *)(result + 24);
    v17 = (unsigned __int8)*a2;
    goto LABEL_28;
  }
  v11 = (_DWORD *)clsh_state_fp[v9];
  if ( *(v11 - 1) != -12605800 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _BYTE *, _QWORD, _QWORD))v11)(result, a2, a4, 0);
  *a2 = v10;
  if ( (unsigned __int8)a4 <= 8u && ((1 << a4) & 0x116) != 0 )
    *(_DWORD *)&a2[4 * __clz(__rbit32(a4)) + 16] = 9;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
