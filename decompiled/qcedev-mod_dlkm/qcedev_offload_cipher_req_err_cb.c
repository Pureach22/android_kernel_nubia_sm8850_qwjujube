__int64 __fastcall qcedev_offload_cipher_req_err_cb(__int64 result, _BYTE *a2)
{
  __int64 *v2; // x8
  __int64 v3; // x8
  __int64 v4; // x8
  int v5; // w9

  if ( result )
  {
    v2 = *(__int64 **)(result + 80);
    if ( v2 )
    {
      v3 = *v2;
      if ( v3 )
      {
        v4 = *(_QWORD *)(v3 + 264);
        if ( v4 )
        {
          *(_DWORD *)(v4 + 812) = 0;
          if ( (a2[1] & 1) != 0 )
          {
            v5 = 2;
          }
          else if ( (a2[2] & 1) != 0 )
          {
            v5 = 3;
          }
          else if ( (a2[3] & 1) != 0 )
          {
            v5 = 1;
          }
          else if ( (a2[4] & 1) != 0 )
          {
            v5 = 4;
          }
          else if ( (a2[6] & 1) != 0 )
          {
            v5 = 6;
          }
          else if ( (a2[8] & 1) != 0 )
          {
            v5 = 7;
          }
          else if ( (a2[7] & 1) != 0 )
          {
            v5 = 8;
          }
          else
          {
            if ( a2[5] != 1 )
            {
LABEL_22:
              *(_BYTE *)(v4 + 947) = 1;
              return complete(v4 + 16);
            }
            v5 = 5;
          }
          *(_DWORD *)(v4 + 812) = v5;
          goto LABEL_22;
        }
      }
    }
  }
  return result;
}
