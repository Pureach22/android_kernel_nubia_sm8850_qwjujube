__int64 __fastcall hdcp1_ops_notify_qseecom(__int64 a1, _DWORD *a2, char a3)
{
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w9
  __int64 v7; // x19

  if ( a1 && (v4 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 24) & 1) != 0 )
      {
        v5 = *(_QWORD *)(v4 + 8);
        *(_QWORD *)v5 = 0x800200000001LL;
        *(_BYTE *)(v5 + 196) = a3 & 1;
        *(_DWORD *)(v5 + 172) = *a2;
        *(_DWORD *)(v5 + 176) = a2[1];
        *(_DWORD *)(v5 + 180) = a2[2];
        v6 = a2[3];
        *(_QWORD *)(v5 + 188) = 0;
        *(_QWORD *)(v5 + 8) = 0;
        *(_QWORD *)(v5 + 16) = 0;
        *(_QWORD *)(v5 + 24) = 0;
        *(_QWORD *)(v5 + 32) = 0;
        *(_QWORD *)(v5 + 40) = 0;
        *(_QWORD *)(v5 + 48) = 0;
        *(_QWORD *)(v5 + 56) = 0;
        *(_QWORD *)(v5 + 64) = 0;
        *(_DWORD *)(v5 + 184) = v6;
        *(_QWORD *)(v5 + 72) = 0;
        *(_QWORD *)(v5 + 80) = 0;
        *(_QWORD *)(v5 + 88) = 0;
        *(_QWORD *)(v5 + 96) = 0;
        *(_QWORD *)(v5 + 104) = 0;
        *(_QWORD *)(v5 + 112) = 0;
        *(_QWORD *)(v5 + 120) = 0;
        *(_QWORD *)(v5 + 128) = 0;
        *(_QWORD *)(v5 + 136) = 0;
        *(_QWORD *)(v5 + 144) = 0;
        *(_QWORD *)(v5 + 152) = 0;
        *(_QWORD *)(v5 + 160) = 0;
        v7 = *(_QWORD *)(v4 + 8);
        qseecom_send_command();
        if ( (*(_DWORD *)(v7 + 260) & 0x80000000) == 0 )
          return 0;
        printk(&unk_CD33);
      }
      else
      {
        printk(&unk_C830);
      }
    }
    else
    {
      printk(&unk_C905);
    }
  }
  else
  {
    printk(&unk_D0E9);
  }
  return 4294967274LL;
}
