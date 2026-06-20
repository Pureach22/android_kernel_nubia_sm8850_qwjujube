__int64 __fastcall hif_map_service_to_pipe(__int64 a1, unsigned __int16 a2, _BYTE *a3, _BYTE *a4, int *a5, _DWORD *a6)
{
  unsigned int v12; // w8
  unsigned int v13; // w22
  char v14; // w25
  char v15; // w11
  unsigned __int8 *v16; // x10
  unsigned __int64 v17; // x8
  int v18; // w13
  __int64 v19; // x12
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v21 = 0;
  hif_select_service_to_pipe_map(a1, v22, (int *)&v21);
  v12 = v21;
  *a6 = 0;
  if ( v12 <= 0xB )
  {
    qdf_trace_msg(61, 8, "%s: ul pipe is NOT updated for service %d", "hif_map_service_to_pipe", a2);
    v13 = -22;
LABEL_14:
    qdf_trace_msg(61, 8, "%s: dl pipe is NOT updated for service %d", "hif_map_service_to_pipe", a2);
    goto LABEL_15;
  }
  v14 = 0;
  v15 = 0;
  v13 = -22;
  v16 = (unsigned __int8 *)(v22[0] + 8LL);
  v17 = v12 / 0xCuLL;
  do
  {
    if ( *((_DWORD *)v16 - 2) == a2 )
    {
      v18 = *((_DWORD *)v16 - 1);
      v19 = *v16;
      if ( v18 == 1 )
      {
        v13 = 0;
        v14 = 1;
        *a4 = v19;
      }
      else if ( v18 == 2 )
      {
        *a3 = v19;
        v13 = 0;
        *a5 = (*(_DWORD *)(*(_QWORD *)(a1 + 27400) + 32 * v19) >> 3) & 1;
        v15 = 1;
      }
      else
      {
        v13 = 0;
      }
    }
    --v17;
    v16 += 12;
  }
  while ( v17 );
  if ( (v15 & 1) == 0 )
    qdf_trace_msg(61, 8, "%s: ul pipe is NOT updated for service %d", "hif_map_service_to_pipe", a2);
  if ( (v14 & 1) == 0 )
    goto LABEL_14;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v13;
}
