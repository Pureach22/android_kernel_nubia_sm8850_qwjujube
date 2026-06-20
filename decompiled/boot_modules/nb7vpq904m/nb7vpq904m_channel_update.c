__int64 __fastcall nb7vpq904m_channel_update(__int64 result)
{
  int v1; // w8
  int v2; // w9
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x22

  v2 = *(_DWORD *)(result + 120);
  v1 = *(_DWORD *)(result + 124);
  v3 = result;
  if ( *(_BYTE *)(result + 165) )
    v2 = v2 == 0;
  if ( v1 <= 2 )
  {
    if ( v1 == 1 )
    {
      if ( v2 )
        v4 = -65536;
      else
        v4 = 0xFFFF;
    }
    else
    {
      if ( v1 != 2 )
        return result;
      v4 = 16843009;
    }
    goto LABEL_16;
  }
  if ( v1 == 3 )
  {
    if ( v2 )
      v4 = 16842752;
    else
      v4 = 257;
LABEL_16:
    *(_DWORD *)(result + 128) = v4;
    goto LABEL_17;
  }
  if ( v1 != 4 )
    return result;
  *(_DWORD *)(result + 128) = 0;
LABEL_17:
  v5 = 0;
  while ( 1 )
  {
    v6 = *(unsigned __int8 *)(v3 + v5 + 128);
    if ( v6 != 255 )
    {
      if ( (unsigned int)v6 > 1 )
      {
        __break(0x5512u);
        JUMPOUT(0x6DF8);
      }
      v7 = v3 + 4 * v6;
      LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64))nb7vpq904m_param_config)(
                          v3,
                          1,
                          (unsigned int)v5,
                          *(unsigned __int8 *)(v3 + v5 + 128),
                          7,
                          1,
                          *(unsigned __int8 *)(v7 + v5 + 132),
                          v3 + 132);
      if ( (_DWORD)result )
        break;
      LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64))nb7vpq904m_param_config)(
                          v3,
                          24,
                          (unsigned int)v5,
                          (unsigned int)v6,
                          3,
                          0,
                          *(unsigned __int8 *)(v7 + v5 + 156),
                          v3 + 156);
      if ( (_DWORD)result )
        break;
      v8 = v7 + v5;
      LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64))nb7vpq904m_param_config)(
                          v3,
                          2,
                          (unsigned int)v5,
                          (unsigned int)v6,
                          11,
                          1,
                          *(unsigned __int8 *)(v8 + 140),
                          v3 + 140);
      if ( (_DWORD)result )
        break;
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64))nb7vpq904m_param_config)(
                 v3,
                 25,
                 (unsigned int)v5,
                 (unsigned int)v6,
                 3,
                 0,
                 *(unsigned __int8 *)(v8 + 148),
                 v3 + 148);
      if ( (_DWORD)result )
        break;
    }
    if ( ++v5 == 4 )
      return result;
  }
  return dev_err(*(_QWORD *)(v3 + 88), "channel parameters update failure(%d).\n", result);
}
